import streamlit as st
import pandas as pd
from NaiveBayes import NaiveBayes

st.set_page_config(layout='centered')

st.title("Naive Bayes Classifier")
st.markdown("By [@JuliusAlphonso](https://twitter.com/JuliusAlphonso)")

dataset = st.sidebar.file_uploader("Choose a file")
probability_selector = st.sidebar.selectbox("Probability", ['simple', 'm-estimate', 'laplace'])

if dataset is not None:
    df = pd.read_csv(dataset, sep='\s+')
else:
    st.markdown("""
            1. From the sidebar, select a tsv file to get started
            2. Also select a probability estimate
            3. Wait for the classifier to finish training fitting onto the data
            4. Once training in complete, you can explore the calculated probabilities
            5. Use the form generated to predict classes for unseen examples
            """
    )
    st.header("Don't have a dataset? Load a demo")
    demosets = {
        'Tennis': 'https://raw.githubusercontent.com/JadeMaveric/GEC/main/ML/data/data.id3.csv',
        'Cars': 'https://raw.githubusercontent.com/JadeMaveric/GEC/main/ML/data/data.tutorial.3.csv',
        'Customers': 'https://raw.githubusercontent.com/JadeMaveric/GEC/main/ML/data/data.tutorial.6.csv'
    }

    dataset = st.selectbox('Dataset', ['None']+list(demosets.keys()))
    
    if dataset != 'None':
        df = pd.read_csv(demosets[dataset], sep='\s+')
    else:
        df = None


if df is not None:
    nb = NaiveBayes()
    nb.fit(df, probability_selector)

    with st.beta_expander("Dataset", expanded=True):
        st.header("Dataset")
        st.write(df)

    with st.beta_expander("Probabilities", expanded=False):
        st.subheader("Prior Probabilities")
        st.write(nb.prior)
        st.subheader("Likelihood")
        st.write(nb.likelihood)
        st.subheader("Evidence")
        st.write(nb.evidence)

    st.header("Classify a record")
    with st.form(key='test_record'):
        attribs = [
            st.selectbox(attrib, list(df[attrib].unique()))
            for attrib in nb.attribs
        ]
        submit_button = st.form_submit_button(label='Submit')
    
    if submit_button:
        ans = nb.predict(attribs)
        sorted_ans = sorted(ans, key=ans.__getitem__, reverse=True)
        ans = {key: ans[key] for key in sorted_ans}

        st.write(pd.DataFrame(ans, index=[0]))

