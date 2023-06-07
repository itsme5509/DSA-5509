#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() {
    ofstream file("student.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;

    file.close();
    cout << "Student added successfully!" << endl;
}

void deleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number of the student to delete: ";
    cin >> rollNumber;

    ifstream inputFile("student.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        cout << "Error creating temporary file!" << endl;
        return;
    }

    bool studentFound = false;
    Student student;
    while (inputFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            studentFound = true;
        } else {
            tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (studentFound) {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
        remove("temp.txt");
    }
}

void displayStudent() {
    int rollNumber;
    cout << "Enter Roll Number of the student to display: ";
    cin >> rollNumber;

    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool studentFound = false;
    Student student;
    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            studentFound = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    file.close();

    if (!studentFound) {
        cout << "Student not found!" << endl;
    }
}

int main() 
{
    int choice;
    do
    {
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display student" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:	
                addStudent();
                break;
            
            case 2:
            	deleteStudent();
            	break;
            
            case 3:
            	displayStudent();
            	break;
            
        
		}
	}while(choice!=4);

}
