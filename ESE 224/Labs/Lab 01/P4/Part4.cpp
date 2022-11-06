#include "Grade.cpp"
#include <iostream>
using namespace std;

int main()
{
    Grade g1;
    double hw, lab, project, exam, total;
    cout << "Enter the grade for each part: " << endl;

    cout << "hw(0-100): ";
    cin >> hw;
    g1.setHW(hw);

    cout << "lab(0-100): ";
    cin >> lab;
    g1.setLab(lab);

    cout << "project(0-100): ";
    cin >> project;
    g1.setProject(project);

    cout << "exam(0-100): ";
    cin >> exam;
    g1.setExam(exam);

    total = g1.getGrade();
    cout << "Total grade(0-100): " << total << endl;
    return 0;
}