#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    string grade;

    // Constructor
    Student(string n, int r, string g) {
        name = n;
        rollNumber = r;
        grade = g;
    }
};

class StudentDatabase {
private:
    vector<Student> students;

public:
    // Function to add a student
    void addStudent(string name, int rollNumber, string grade) {
        Student newStudent(name, rollNumber, grade);
        students.push_back(newStudent);
    }

    // Function to display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students in the database.\n";
            return;
        }
        cout << "Student Database:\n";
        cout << "Name\t\tRoll No.\tGrade\n";
        for (const auto &student : students) {
            cout << student.name << "\t\t" << student.rollNumber << "\t\t" << student.grade << "\n";
        }
    }

    // Function to search for a student by roll number
    void searchStudentByRollNumber(int rollNumber) {
        for (const auto &student : students) {
            if (student.rollNumber == rollNumber) {
                cout << "Student found:\n";
                cout << "Name: " << student.name << "\n";
                cout << "Roll No.: " << student.rollNumber << "\n";
                cout << "Grade: " << student.grade << "\n";
                return;
            }
        }
        cout << "Student with Roll No. " << rollNumber << " not found.\n";
    }
};

int main() {
    StudentDatabase db;

    db.addStudent("John Doe", 101, "A");
    db.addStudent("Jane Smith", 102, "B");
    db.addStudent("Emily Davis", 103, "A");

    db.displayStudents();

    cout << "Enter roll number to search: ";
    int rollNo;
    cin >> rollNo;
    db.searchStudentByRollNumber(rollNo);

    return 0;
}
