#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

void addEmployee() {
    ofstream file("employee.txt", ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee employee;
    cout << "Enter Employee ID: ";
    cin >> employee.employeeID;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, employee.name);
    cout << "Enter Designation: ";
    getline(cin, employee.designation);
    cout << "Enter Salary: ";
    cin >> employee.salary;

    file.write(reinterpret_cast<char*>(&employee), sizeof(employee));

    file.close();
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee() {
    int employeeID;
    cout << "Enter Employee ID of the employee to delete: ";
    cin >> employeeID;

    fstream file("employee.txt", ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee employee;
    bool employeeFound = false;
    while (file.read(reinterpret_cast<char*>(&employee), sizeof(employee))) {
        if (employee.employeeID == employeeID) {
            employeeFound = true;
            break;
        }
    }

    if (employeeFound) {
        streampos position = file.tellg();
        file.seekp(position - sizeof(employee));
        Employee emptyEmployee{};
        file.write(reinterpret_cast<char*>(&emptyEmployee), sizeof(emptyEmployee));
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }

    file.close();
}

void displayEmployee() {
    int employeeID;
    cout << "Enter Employee ID of the employee to display: ";
    cin >> employeeID;

    ifstream file("employee.txt", ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee employee;
    bool employeeFound = false;
    while (file.read(reinterpret_cast<char*>(&employee), sizeof(employee))) {
        if (employee.employeeID == employeeID) {
            employeeFound = true;
            cout << "Employee ID: " << employee.employeeID << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Designation: " << employee.designation << endl;
            cout << "Salary: " << employee.salary << endl;
            break;
        }
    }

    file.close();

    if (!employeeFound) {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add employee" << endl;
        cout << "2. Delete employee" << endl;
        cout << "3. Display employee" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.";
		}
	}while(choice != 4);
}
