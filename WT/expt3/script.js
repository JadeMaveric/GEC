let state = {
    login: false
};

let loginPage = document.getElementById('login-page');
let loginButton = document.getElementById('login-button');
let closeLogin = document.getElementById('login-close');
let loginForm = loginPage.children[0]
let submitLogin = document.getElementById('login-submit')

loginButton.onclick = () => {
    if (state.login) {
        state.login = false;
        loginButton.innerText = "Login";
    }
    else {
        loginPage.style.display = "block";
    }
}
closeLogin.onclick = () => {
    loginPage.style.display = "none";
}

submitLogin.onclick = (event) => {
    let validDetails = validateForm();
    if (validDetails) {
        state.login = true;
        loginButton.innerHTML = "Logout";
        loginPage.style.display = "none";
    }
}

function validateForm() {
    let returnValue = true
    if (!/^[\w\s]{6,}$/.test(loginForm.elements.name.value)) {
        alert("Invalid Name");
        returnValue = false
    }
    if (!/^.{6,}$/.test(loginForm.elements.password.value)) {
        alert("Invalid Password");
        returnValue = false
    }
    if (!/^\w+([.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(loginForm.elements.email.value)) {
        alert("Invalid Email");
        returnValue = false
    }
    if (!/^\d{10}$/.test(loginForm.elements.phone.value)) {
        alert("Invalid Phone number");
        returnValue = false
    }

    return returnValue;
}

function toggleCart( bookIndex ) {1
    if (!state.cart)
        state.cart = []
    
    let idx = state.cart.indexOf(bookIndex);
    let bookshelf = document.getElementById('bookshelf');
    
    if (idx == -1) {
        state.cart.push(bookIndex)
        let button = bookshelf.children[bookIndex+1].children[4];
        button.innerText = "Del";
        button.className = "del";

    }
    else {
        state.cart.splice(idx,1)
        let button = bookshelf.children[bookIndex+1].children[4];
        button.innerText = "Add";
        button.className = "add";
    }
    
}

function buildTable( books ) {
    let bookshelf = document.getElementById('bookshelf')
    state.cart = Array(books.length).fill().map((x,i)=>i)

    let header = document.createElement('thead');
    for (key in books[0]) {
        let data = document.createElement('th');
        data.innerText = key;
        header.appendChild(data);
    }
    bookshelf.appendChild(header);

    books.forEach((book, idx) => {
        let row = document.createElement('tr');
        for (key in book) {
            let data = document.createElement('td');
            data.innerText = book[key];
            row.appendChild(data);
        };
        let a2c = document.createElement('button')
        a2c.innerText = "Del"
        a2c.bookIndex = idx
        a2c.className = "del"
        a2c.onclick = event =>toggleCart(event.target.bookIndex)
        row.append(a2c)
        bookshelf.appendChild(row)
    });
}

fetch("./books.json")
.then( res => {
    return res.json();
})
.then( data => buildTable(data) )

