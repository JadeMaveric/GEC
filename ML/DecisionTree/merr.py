import streamlit as st
import pandas as pd
from anytree import Node, RenderTree
import graphviz
from anytree.exporter import UniqueDotExporter

st.set_page_config( layout='wide' )

# -------- FUNCTIONS -------- #
def format_data(dataset):
    df = pd.read_csv(dataset, sep='\s+')

    attr_cols = df.columns[:-1]
    targ_cols = df.columns[-1]
    df[targ_cols] = df[targ_cols].apply(
        lambda x: True if x in ('Positive', 'Yes', True) else False
    )
    return df


def missclassification_error(data, attr):
    if not attr in data.columns:
        raise ValueError(f"{attr} not found in {data.columns}")

    target = data.columns[-1]
    counts = {
        value: {
            True: sum((data[attr] == value) & (data[target] == True)),
            False: sum((data[attr] == value) & (data[target] == False))
        } for value in sorted(data[attr].unique())
    }

    counts_df = pd.DataFrame(counts)
    me_dataset = min(sum(data[target]==True), sum(data[target]==False) / data[target].count())
    me_attr = counts_df.apply(
        lambda x: min(x[True], x[False])/data[target].count()
    )
    me_gain = me_dataset - sum(me_attr)
    
    # Format output
    counts_df = counts_df.transpose()
    counts_df['Msc Err.'] = me_attr
    return counts_df, me_dataset, sum(me_attr), me_gain


def select_splitting_attr(data, display=False):
    if len(data.columns) <= 1:
        raise ValueError("Only target attribute in dataset, can't split further")
    
    loss = []

    for attr in sorted(data.columns[:-1]):
        counts_df, me_data, me_attr, me_gain = missclassification_error(data, attr)
        if display:
            with st.beta_expander(attr, True):
                calc, table = st.beta_columns(2)
                calc.write(f"Gain = {me_data} - {me_attr}")
                calc.write(f"Gain = {round(me_gain, 4)}")
                table.write(counts_df)
        loss.append((round(me_attr, 4), attr))

    loss = sorted(loss)
    return loss[0]


def build_tree(data, edge_name="", parent=None, path=""):
    global labeled_count, node_count
    target = data.columns[-1]
    path = f"{path}/{edge_name}"

    # Return leaf nodes
    if len(data.columns) <= 1:
        if sum(data[target] == True) > sum(data[target] == False):
            name = "True"
        else:
            name = "False"
        node = Node(name, parent=parent, data=data, label=edge_name)
        labeled_count += len(data)
        nodes_processed.progress(labeled_count / total_count)
        progress_text.text(f"{labeled_count}/{total_count} datapoints processed")

    # Build intermediate node
    else:
        loss, split_attrib = select_splitting_attr(data)
        name = split_attrib
        node = Node(name, parent=parent, data=data, label=edge_name)
        for value in sorted(data[split_attrib].unique()):
            sub_data = data[data[split_attrib] == value].drop(split_attrib, axis=1)
            build_tree(sub_data, value, node, path)
    
    rules[path] = node
    return node   

            
# -------- GLOBAL VARS -------- #
total_count = 0
labeled_count = 0
node_count = 0
rules = {}

# -------- MAIN -------- #
dataset = st.sidebar.file_uploader("Choose a file")
nodes_processed = st.sidebar.progress(0)
progress_text = st.sidebar.empty()

if dataset is not None:
    df = format_data(dataset)
    total_count = len(df)
    progress_text.text(f"{labeled_count}/{total_count} datapoints processed")
 
    root = build_tree(df, "root")
    node_attr_func = lambda node: f"shape={'box' if node.name in ['True', 'False'] else 'ellipse'}, label={node.name}"
    edge_name_func = lambda parent, child: f"style=bold,label={child.label or ''}"
    dot_data = UniqueDotExporter(root, nodeattrfunc=node_attr_func, edgeattrfunc=edge_name_func)
    dot_data = '\n'.join(dot_data)
    graph = graphviz.Source(dot_data)
    st.graphviz_chart(dot_data)
    
    node_names = list(reversed(rules.keys()))
    nodepath = st.selectbox("Node", node_names)
    
    data = rules[nodepath].data
    st.write(data)
    select_splitting_attr(data, True)

    # st.write(RenderTree(root))


