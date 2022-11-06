#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "ShoppingList.h"

ShoppingList::ShoppingList()
{
    price = 0;
    max_price = 0;
    number = 0;
}

bool ShoppingList::fileOpen(std::istream &in)
{
    std::cout << "Please enter the file name: ";
    in >> file_name;
    myFile.open(file_name);

    if (myFile.fail())
    {
        return false;
    }

    std::cout << std::endl
              << std::endl;
    myFile.seekg(0, std::ios::beg);
    while (true)
    {
        if (myFile.eof())
        {
            break;
        }
        std::string temp;
        std::getline(myFile, temp);
        if (!temp.empty())
        {
            number++;
        }
    }

    myFile.clear();

    if (myFile.is_open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ShoppingList::itemExists(std::istream &in)
{
    std::cout << "Enter the item name: ";
    std::string existsName;
    in >> existsName;
    myFile.seekg(0, std::ios::beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);

        std::string itemName = temp.substr(0, temp.find(' '));
        std::string itemPrice = temp.substr(temp.find(' ') + 1, temp.length() - 1);

        if (existsName == itemName)
        {
            std::cout << "Item exists and costs " << itemPrice << std::endl
                      << std::endl;
            return true;
        }
    }
    return false;
}

void ShoppingList::addItem(std::istream &in)
{

    std::cout << "What is the name of the item to add: ";
    std::string itemToAdd;
    in >> itemToAdd;
    std::cout << "What is the price of the item to add: ";
    double priceToAdd;
    in >> priceToAdd;

    myFile.seekg(0, std::ios::end);

    if (myFile.is_open())
    {
        myFile << itemToAdd << " " << priceToAdd << std::endl;
        // myFile.flush();
        number++;
    }
    std::cout << std::endl
              << std::endl;
}

void ShoppingList::printMostExpensiveItem()
{
    myFile.seekg(0, myFile.beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);
        std::string itemName = temp.substr(0, temp.find(' '));
        double itemCost = stod(temp.substr(temp.find(' ')));
        if (i == 0)
        {
            most_expensive_item = itemName;
            max_price = itemCost;
        }
        else
        {
            if (itemCost > max_price)
            {
                most_expensive_item = itemName;
                max_price = itemCost;
            }
        }
    }

    std::cout << "Most expensive item is: " << most_expensive_item
              << std::endl
              << "It costs " << max_price
              << std::endl
              << std::endl;
}

void ShoppingList::printAll()
{
    myFile.seekg(0, myFile.beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);
        std::string itemName = temp.substr(0, temp.find(' '));
        double itemCost = stod(temp.substr(temp.find(' ')));

        std::cout << itemName << " " << itemCost << std::endl;
    }
    std::cout << std::endl;
}

void ShoppingList::printTranspose()
{
    myFile.seekg(0, myFile.beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);
        std::string itemName = temp.substr(0, temp.find(' '));

        std::cout << std::left << std::setw(20) << itemName;
    }
    std::cout << std::endl;

    myFile.seekg(0, myFile.beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);
        double itemCost = stod(temp.substr(temp.find(' ')));

        std::cout << std::left << std::setw(20) << itemCost;
    }

    std::cout << std::endl
              << std::endl;
}

void ShoppingList::priceSort()
{
    struct item
    {
        std::string name2;
        double price2;
    };

    item newArr[number];
    myFile.seekg(0, myFile.beg);
    for (int i = 0; i < number; i++)
    {
        std::string temp;
        std::getline(myFile, temp);
        std::string itemName = temp.substr(0, temp.find(' '));
        double itemCost = stod(temp.substr(temp.find(' ')));

        newArr[i].name2 = itemName;
        newArr[i].price2 = itemCost;
    }

    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < number - 1; i++)
        {
            if (newArr[i].price2 > newArr[i + 1].price2)
            {
                std::swap(newArr[i], newArr[i + 1]);
                sorted = false;
            }
        }
    }

    for (int i = 0; i < number; i++)
    {
        std::cout << std::left << (i + 1) << ". " << std::setw(20) << newArr[i].name2 << std::setw(10) << newArr[i].price2 << std::endl;
    }
    std::cout << std::endl;
}
