
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, choice, pos;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Choose an insertion option:\n";
    cout << "1. Insert at the beginning\n";
    cout << "2. Insert at the end\n";
    cout << "3. Insert at a specific position\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;

            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            newNode->prev = nullptr;

            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;

            if (tail == nullptr) {
                tail = newNode;
            }
            break;
        }
        case 2: {
            int value;
            cout << "Enter the value to insert at the end: ";
            cin >> value;

            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            newNode->prev = tail;

            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;

            if (head == nullptr) {
                head = newNode;
            }
            break;
        }
        case 3: {
            cout << "Enter the position (0 to " << n << ") to insert: ";
            cin >> pos;
            if (pos < 0 || pos > n) {
                cout << "Invalid position!" << endl;
                return 1;
            }

            int value;
            cout << "Enter the value to insert at position " << pos << ": ";
            cin >> value;

            Node* newNode = new Node();
            newNode->data = value;

            if (pos == 0) {
                newNode->next = head;
                newNode->prev = nullptr;
                if (head != nullptr) {
                    head->prev = newNode;
                }
                head = newNode;
                if (tail == nullptr) {
                    tail = newNode;
                }
            } else {
                Node* current = head;
                for (int i = 0; i < pos - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;

                if (newNode->next == nullptr) {
                    tail = newNode;
                }
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }
      