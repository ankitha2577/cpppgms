#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Shortest way to add nodes
void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Detect Loop Function
void detectLoop() {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Move 1 step
        fast = fast->next->next; // Move 2 steps

        if (slow == fast) {
            cout << "Loop FOUND!\n";
            return;
        }
    }
    cout << "NO Loop found.\n";
}

int main() {
    int n, val, choice;

    cout << "How many nodes? ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    // Ask user if they want to test with a loop
    cout << "Do you want to create a loop? (1 for Yes, 0 for No): ";
    cin >> choice;

    if (choice == 1 && head != NULL) {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Walk to last node
        }
        temp->next = head; // Connect last node back to head to make a loop!
    }

    detectLoop();

    return 0;
}
