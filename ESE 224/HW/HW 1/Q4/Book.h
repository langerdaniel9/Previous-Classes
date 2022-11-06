#include <string>
#include <iostream>

using namespace std;

class Book
{
private:
    int number, pages;
    string title, author, genre;

public:
    Book(int initNumber, string initTitle, string initAuthor, string initGenre, int initPages);
    Book operator=(const Book &b2) const;
    void print();
};

Book::Book(int initNumber, string initTitle, string initAuthor, string initGenre, int initPages)
{
    number = initNumber;
    title = initTitle;
    author = initAuthor;
    genre = initGenre;
    pages = initPages;
}

Book Book::operator=(const Book &b2) const
{
    return Book(b2.number, b2.title, b2.author, b2.genre, b2.pages);
}

void Book::print()
{
    cout << "Number: " << number << ", Title: " << title << ", Author: " << author << ", Genre: " << genre << ", Pages: " << pages << endl;
}