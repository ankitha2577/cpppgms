#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int numberOfNodes;

    cout << "How many nodes do you want in the list? ";
    cin >> numberOfNodes;

    for (int i = 0; i < numberOfNodes; i++) {
        int value;
        cout << "Enter a value: ";
        cin >> value;

        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int value;
    cout << "Enter the value to insert at the end: ";
    cin >> value;

    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;

    cout << "List after insertion: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}
