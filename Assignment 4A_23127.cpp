// A. Implement Queue using an Array and Linked List to perform basic operations such 
// as Enqueue, Dequeue, Front, Display, and Check whether Queue is Empty or Full.

#include <iostream>
using namespace std;

#define MAX 5   // Max size for array-based queue (circular array)

// QUEUE USING CIRCULAR ARRAY
class ArrayQueue {
    int arr[MAX];
    int front, rear;
public:
    ArrayQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (rear + 1) % MAX == front; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        if (front == rear) { // last element removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// QUEUE USING LINKED LIST
struct Node {
    int data;
    Node* next;
};

class LinkedListQueue {
    Node *front, *rear;
public:
    LinkedListQueue() { front = rear = nullptr; }

    bool isEmpty() { return front == nullptr; }
    bool isFull()  { return false; } // bounded only by available memory

    void enqueue(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Queue Overflow! Memory not available.\n";
            return;
        }
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue.\n";
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedListQueue() {
        while (!isEmpty()) dequeue();
    }
};

// MENU DRIVEN MAIN FUNCTION
int main() {
    int impChoice;
    cout << "===== QUEUE IMPLEMENTATION =====\n";
    cout << "1. Array based Queue (Max size = " << MAX << ")\n";
    cout << "2. Linked List based Queue\n";
    cout << "Enter your choice: ";
    cin >> impChoice;

    int choice, value;
    ArrayQueue aQueue;
    LinkedListQueue lQueue;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (impChoice == 1) aQueue.enqueue(value);
                else lQueue.enqueue(value);
                break;
            case 2:
                if (impChoice == 1) aQueue.dequeue();
                else lQueue.dequeue();
                break;
            case 3:
                if (impChoice == 1) aQueue.getFront();
                else lQueue.getFront();
                break;
            case 4:
                if (impChoice == 1) aQueue.display();
                else lQueue.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
