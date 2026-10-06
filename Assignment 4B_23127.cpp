// B. Develop a Hospital Emergency Room Management System using a Priority Queue. 
// The system should allow users to register patients along with their priority level 
// (e.g., Critical, Serious, Normal), display the waiting queue, and serve patients based 
// on priority basis. 

#include <iostream>
#include <string>
using namespace std;

// Lower number = higher priority
enum Priority { CRITICAL = 1, SERIOUS = 2, NORMAL = 3 };

struct Patient {
    int id;
    string name;
    int priority;
    Patient* next;
};

class HospitalPriorityQueue {
    Patient* front;
    int patientCounter;

    string priorityName(int p) {
        if (p == CRITICAL) return "Critical";
        if (p == SERIOUS)  return "Serious";
        return "Normal";
    }

public:
    HospitalPriorityQueue() {
        front = nullptr;
        patientCounter = 100; // starting patient ID
    }

    bool isEmpty() { return front == nullptr; }

    // Insert patient in order of priority.
    // Among patients with the same priority, the earlier registered
    // patient stays ahead (FIFO within same priority level).
    void registerPatient(string name, int priority) {
        Patient* newPatient = new Patient();
        newPatient->id = ++patientCounter;
        newPatient->name = name;
        newPatient->priority = priority;
        newPatient->next = nullptr;

        if (isEmpty() || priority < front->priority) {
            newPatient->next = front;
            front = newPatient;
        } else {
            Patient* temp = front;
            // move forward while next node has priority <= new patient's priority
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newPatient->next = temp->next;
            temp->next = newPatient;
        }

        cout << "Patient \"" << name << "\" registered with ID " << newPatient->id
             << " (Priority: " << priorityName(priority) << ")\n";
    }

    // Serve (remove) the patient at the front of the queue -highest priority first
    void servePatient() {
        if (isEmpty()) {
            cout << "No patients waiting. Queue is empty.\n";
            return;
        }
        Patient* temp = front;
        cout << "Serving Patient ID " << temp->id << " - " << temp->name
             << " (" << priorityName(temp->priority) << ")\n";
        front = front->next;
        delete temp;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "\n--- Emergency Room Waiting Queue ---\n";
        cout << "ID\tName\t\tPriority\n";
        Patient* temp = front;
        while (temp != nullptr) {
            cout << temp->id << "\t" << temp->name << "\t\t"
                 << priorityName(temp->priority) << endl;
            temp = temp->next;
        }
        cout << "-------------------------------------\n";
    }

    ~HospitalPriorityQueue() {
        while (!isEmpty()) {
            Patient* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// MENU DRIVEN MAIN
int main() {
    HospitalPriorityQueue er;
    int choice;

    do {
        cout << "\n===== Hospital Emergency Room Management System =====\n";
        cout << "1. Register New Patient\n";
        cout << "2. Display Waiting Queue\n";
        cout << "3. Serve Next Patient (highest priority)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int pChoice, priority;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Select priority:\n 1. Critical\n 2. Serious\n 3. Normal\n";
                cout << "Enter choice (1-3): ";
                cin >> pChoice;

                if (pChoice == 1) priority = CRITICAL;
                else if (pChoice == 2) priority = SERIOUS;
                else priority = NORMAL;

                er.registerPatient(name, priority);
                break;
            }
            case 2:
                er.displayQueue();
                break;
            case 3:
                er.servePatient();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
