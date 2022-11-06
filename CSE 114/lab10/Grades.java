/*
 * Daniel Langer
 * 114662901
 */

import java.util.Scanner;

class Student {
    String name;
    double test1, test2 = 0;
    Scanner input = new Scanner(System.in);

    public Student(String studentName) {
        name = studentName;
    }

    public void inputGrades() {
        System.out.println("What is " + name + "'s score for test 1?");
        test1 = input.nextDouble();
        while (test1 < 0 || test1 > 100) {
            System.out.println("Invalid input, try again\nWhat is " + name + "'s score for test 1?");
            test1 = input.nextDouble();
        }
        System.out.println("What is " + name + "'s score for test 2?");
        test2 = input.nextDouble();
        while (test2 < 0 || test2 > 100) {
            System.out.println("Invalid input, try again\nWhat is " + name + "'s score for test 2?");
            test2 = input.nextDouble();
        }
    }

    public double getAverage() {
        return (test1 + test2) / 2;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return ("Name: " + name + " Test1: " + test1 + " Test2: " + test2);
    }
}

// ****************************************************************
// Grades.java
//
// Use Student class to get test grades for two students
// and compute averages
//
// ****************************************************************

public class Grades {
    public static void main(String[] args) {
        Student student1 = new Student("Mary");
        Student student2 = new Student("Mike");

        // input grades for Mary
        student1.inputGrades();
        // print average for Mary
        System.out.println("The average for " + student1.getName() + " is " + student1.getAverage());

        System.out.println();

        // input grades for Mike
        student2.inputGrades();
        // print average for Mike
        System.out.println("The average for Mike  " + student2.getName() + " is " + student2.getAverage());

        System.out.println("Student 1: " + student1);

    }
}