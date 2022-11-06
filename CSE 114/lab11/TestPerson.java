/*
 * Daniel Langer
 * 114662901
 */

import java.time.*;

enum ClassYear {
    FRESHMAN, SOPHOMORE, JUNIOR, SENIOR
};

class MyDate {
    private int year;
    private int month;
    private int day;

    public MyDate(int initMonth, int initDay, int initYear) {
        month = initMonth;
        day = initDay;
        year = initYear;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }
}

class Person {
    private String name;
    private String address;
    private String phoneNumber;
    private int age;
    private String emailAddress;

    public Person(String initName) {
        name = initName;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return "[Person] name: " + name;
    }
}

class Student extends Person {
    private ClassYear status;

    public Student(String initName, ClassYear initStatus) {
        super(initName);
        status = initStatus;
    }

    public String toString() {
        return "[Student] name: " + super.getName();
    }
}

class Employee extends Person {
    public Employee(String initName) {
        super(initName);
    }

    private double salary;
    private MyDate dateHired;

    public MyDate getDateHired() {
        return dateHired;
    }

    public String toString() {
        return "[Employee]  name: " + super.getName();
    }
}

class Faculty extends Employee {
    private String officeHours;
    private int rank;

    public Faculty(String initName) {
        super(initName);
    }

    public int salaryRange(int rank) {
        int result;
        int rTy = rank * (Year.now().getValue() - super.getDateHired().getYear());
        if (rTy < 10) {
            result = 1;
        } else if (rTy >= 10 && rTy < 20) {
            result = 2;
        } else {
            result = 3;
        }
        return result;
    }

    public String toString() {
        return "[Faculty] name: " + super.getName();
    }
}

class Staff extends Employee {
    private String title;

    public Staff(String initName) {
        super(initName);
    }

    public String toString() {
        return "[Staff] name: " + super.getName();
    }
}

public class TestPerson {
    public static void main(String[] args) {
        Person someone = new Person("John Doe");
        Student daniel = new Student("Daniel", ClassYear.SOPHOMORE);
        Employee prof = new Employee("Professor");
        Faculty prof2 = new Faculty("Other Professor");
        Staff janitor = new Staff("Janitor");

        System.out.println(someone.toString());
        System.out.println(daniel.toString());
        System.out.println(prof.toString());
        System.out.println(prof2.toString());
        System.out.println(janitor.toString());
    }
}
