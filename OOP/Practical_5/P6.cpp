#include <iostream>
#include <stdlib.h>
using namespace std;

class Stock {
private:
    struct Book {
        char title[20];
        char author[20];
        char publisher[20];
        short price;
        short stock;
    } *book;
    size_t books;

    void add( char* _title, char *_author, char *_publisher, short _price, short _stock ) {
        if( book == nullptr)
            book = (Book*) malloc( sizeof(book) );
        else {
            book = (Book*) realloc( book, sizeof(book)*(books+1) );
        }

        for (int i=0; _title[i]!='\0'; i++)
            book[books].title[i] = _title[i];
        for (int i=0; _author[i]!='\0'; i++)
            book[books].author[i] = _author[i];
        for (int i=0; _publisher[i]!='\0'; i++)
            book[books].publisher[i] = _publisher[i];
        book[books].price = _price;
        book[books].stock = _stock;
    }

    
};