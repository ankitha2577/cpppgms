#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertAtSecondLast(Node*& head, int val) {
    // Case 1: If list is empty or has only 1 node, 
    // there is no second-last position (so we insert at the beginning instead)
    if (head == NULL || head->next == NULL) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "List was too short. Inserted at the beginning instead.\n";
        return;
    }

    // Case 2: Walk until temp is at the SECOND-LAST node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Now 'temp' is pointing at the old second-last node.
    // We want to insert our new node right between 'temp' and 'temp->next'.
    Node* newNode = new Node();
    newNode->data = val;

    newNode->next = temp->next; // New node points to the old last node
    temp->next = newNode;      // Old second-last node points to the new node

    cout << "Element inserted at second-last position !\n";
}
