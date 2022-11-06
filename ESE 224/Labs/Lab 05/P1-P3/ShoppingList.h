#pragma once
#include <string>
#include <fstream>

class ShoppingList
{
private:
    std::string file_name;
    std::fstream myFile;
    std::string most_expensive_item;
    std::string name;
    double price;
    double max_price;
    int number;

public:
    ShoppingList();
    bool fileOpen(std::istream &in);
    bool itemExists(std::istream &in);
    void addItem(std::istream &in);
    void printMostExpensiveItem();
    void printAll();
    void printTranspose();
    void priceSort();
};
