#include <string>
#include "ShoppingList.cpp"

using namespace std;

/*
 * Input file cannot be open or else it will fail
 * Input file is also assumed to have an empty line at the end
 */

int main()
{

    ShoppingList list = ShoppingList();
    cout << "Opening Shopping_List_Manager . . ." << endl
         << endl;

    if (list.fileOpen(cin))
    {
        cout << "Successfully opened the target file!" << endl
             << endl;
    }
    else
    {
        cout << "Cannot open the target file" << endl;
        exit(1);
    }

    cout << "(a) - add an item and print its price" << endl
         << "(e) - print the most expensive item in the list" << endl
         << "(i) - check to see if this item exists" << endl
         << "(p) - print all items and its price" << endl
         << "(q) - quit the program" << endl
         << "(s) - print in price decending order" << endl
         << "(t) - print transposed form" << endl
         << endl;

    bool loop = true;
    while (loop)
    {
        cout << "Please select an option: ";
        char option;
        cin >> option;
        cout << endl;

        switch (tolower(option))
        {
        case 'a':
            list.addItem(cin);
            break;
        case 'e':
            list.printMostExpensiveItem();
            break;
        case 'i':
            if (!list.itemExists(cin))
                cout << "This item is not in the list"
                     << endl
                     << endl;
            break;
        case 'p':
            list.printAll();
            break;
        case 'q':
            loop = false;
            cout << "Exiting the program..." << endl;
            break;
        case 's':
            list.priceSort();
            break;
        case 't':
            list.printTranspose();
            break;
        default:
            cout << "Invalid input, try again" << endl;
            break;
        }
    }
}