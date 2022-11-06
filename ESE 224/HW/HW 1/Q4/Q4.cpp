#include "Book.h"

int main()
{
    Book first(12, "titlea", "author1", "genre", 12);
    Book second(13, "titleb", "author2", "genre", 52);
    Book third(14, "titlec", "author3", "genre", 31);
    Book fourth(15, "titled", "author4", "genre", 72);
    Book fifth = third;

    first.print();
    second.print();
    third.print();
    fourth.print();
    fifth.print();
}