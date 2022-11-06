#include <string>
#include <iostream>
#include "Student.h"

Student::Student()
{
    name = "ESE224 TA";
    id = "1234567890";
    major = "Electrical Engineering";
    email = "ese224ta@stonybrook.edu";
}

Student::Student(std::string initName, std::string initID, std::string initMajor, std::string initEmail)
{
    name = initName;
    id = initID;
    major = initMajor;
    email = initEmail;
}

std::string Student::getName() { return name; }

std::string Student::getID() { return id; }

std::string Student::getMajor() { return major; }

std::string Student::getEmail() { return email; }

void Student::setName(std::string newName) { name = newName; }

void Student::setID(std::string newID) { id = newID; }

void Student::setMajor(std::string newMajor) { major = newMajor; }

void Student::setEmail(std::string newEmail) { email = newEmail; }

void Student::printInfo()
{
    std::cout << "Name is: " + name + ", ID is: " + id + ", major is: " + major + ", email is: " + email + ".\n";
}
