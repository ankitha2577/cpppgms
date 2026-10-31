#include <iostream>
using namespace std;

// 1. Simple Node structure (No classes used)
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// 2. Insert at End (to build the list in order)
void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Find the Middle Node (Slow & Fast Pointer Trick)
void findMiddle() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
    }

    // When fast hits the end, slow is at the exact middle!
    cout << "The middle node is: " << slow->data << endl;
}

// 4. Display the list
void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int n, val;
    cout << "How many nodes? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }

    display();
    findMiddle();

    return 0;
}
