#include "Student.cpp"
#include <iostream>
using namespace std;

int main()
{
     cout << "Default Contructor: " << endl;
     Student s1;
     cout << "Name: " << s1.getName() << "\n"
          << "ID: " << s1.getID() << "\n"
          << "Major: " << s1.getMajor() << "\n"
          << "email: " << s1.getEmail() << "\n"
          << endl;

     cout << "Paramterized Constructor:\nEnter parameters: name, id, major, email" << endl;
     string name, id, major, email;
     getline(cin, name);
     getline(cin, id);
     getline(cin, major);
     getline(cin, email);
     Student s2(name, id, major, email);
     cout << "\nName: " << s2.getName() << "\n"
          << "ID: " << s2.getID() << "\n"
          << "Major: " << s2.getMajor() << "\n"
          << "email: " << s2.getEmail() << "\n"
          << endl;

     cout << "Change student name:\nEnter new name: " << endl;
     string newName;
     getline(cin, newName);
     s2.setName(newName);

     cout << "\nChange id:\nEnter new id: " << endl;
     string newID;
     getline(cin, newID);
     s2.setID(newID);

     cout << "\nChange major:\nEnter new major: " << endl;
     string newMajor;
     getline(cin, newMajor);
     s2.setMajor(newMajor);

     cout << "\nChange email:\nEnter new email: " << endl;
     string newEmail;
     getline(cin, newEmail);
     s2.setEmail(newEmail);

     cout << "\nPrint student information: " << endl;
     s2.printInfo();

     return 0;
}
