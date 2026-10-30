#include <iostream>
using namespace std;

// Simple Node structure
struct Node {
    int data;
    Node* next;
};

// Function to find and print the second last node
void findSecondLast(Node* head) {
    // 1. Check if the list is empty or has only 1 node
    if (head == NULL || head->next == NULL) {
        cout << "Error: There is no second last node (List is too short)!\n";
        return;
    }

    Node* temp = head;

    // 2. Walk forward until temp's next node is the last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 3. temp is now at the second last node!
    cout << "The second last node data is: " << temp->data << endl;
}
