#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to find the address of the k-th node from the end
Node* findKthFromLast(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return NULL; // Invalid list or k
    }

    Node* first = head;
    Node* second = head;

    // 1. Move the 'first' pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            cout << "Error: k is greater than the total number of nodes!\n";
            return NULL;
        }
        first = first->next;
    }

    // 2. Move both pointers together until 'first' reaches the end (NULL)
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // 3. 'second' is now pointing at the k-th node from the last!
    return second;
}
