
#include <iostream>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int priority;
};

struct ComparePatient {
    bool operator()(const Patient& p1, const Patient& p2) {
        return p1.priority > p2.priority; // Higher priority patients have lower values
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, ComparePatient> queue;

    int choice;
    do {
        cout << "1. Add patient" << endl;
        cout << "2. Serve patient" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Patient patient;
                cout << "Enter patient name: ";
                cin >> patient.name;
                cout << "Enter patient priority (1 for serious, 2 for non-serious, 3 for general checkup): ";
                cin >> patient.priority;
                queue.push(patient);
                cout << "Patient added to the queue." << endl;
                break;
            }
            case 2: {
                if (!queue.empty()) {
                    Patient patient = queue.top();
                    queue.pop();
                    cout << "Serving patient: " << patient.name << " (Priority: " << patient.priority << ")" << endl;
                } else {
                    cout << "No patients in the queue." << endl;
                }
                break;
            }
            case 3:
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(choice!= 3);
return 0;
}
