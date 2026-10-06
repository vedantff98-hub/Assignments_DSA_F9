// 3A. Implement the Stack using an Array and Linked List to perform basic operations 
// such as Push, Pop, Peek (Top), Display and Check whether Stack is Empty or Full. 

#include <iostream>
using namespace std;

#define MAX 5   // Max size for array-based stack
// STACK USING ARRAY
class ArrayStack {
    int arr[MAX];
    int top;
public:
    ArrayStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// STACK USING LINKED LIST
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Stack Overflow! Memory not available.\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedListStack() {
        while (!isEmpty()) pop();
    }
};

// MENU DRIVEN MAIN
int main() {
    int impChoice;
    cout << "Welcome to stack implementation program\n";
    cout << "1. Array based Stack (Max size = " << MAX << ")\n";
    cout << "2. Linked List based Stack\n";
    cout << "Enter your choice: ";
    cin >> impChoice;

    int choice, value;
    ArrayStack aStack;
    LinkedListStack lStack;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                if (impChoice == 1) aStack.push(value);
                else lStack.push(value);
                break;
            case 2:
                if (impChoice == 1) aStack.pop();
                else lStack.pop();
                break;
            case 3:
                if (impChoice == 1) aStack.peek();
                else lStack.peek();
                break;
            case 4:
                if (impChoice == 1) aStack.display();
                else lStack.display();
                break;
            case 5:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
