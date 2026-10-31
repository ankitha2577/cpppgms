#include <iostream>
using namespace std;

// 1. Simple Node structure (No classes used)
struct Node {
    int data;
    Node* next;
};

// 2. Insert at End (to build the lists in sorted order)
void insertEnd(Node*& head, int val) {
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

// 3. Merge Two Sorted Linked Lists (The Zipper!)
Node* mergeLists(Node* h1, Node* h2) {
    // Base cases: if one list runs out, attach the other list!
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    // Compare data and pick the smaller node
    if (h1->data <= h2->data) {
        h1->next = mergeLists(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeLists(h1, h2->next);
        return h2;
    }
}

// 4. Display Function
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, val;

    // Input First Sorted List
    cout << "How many elements in Sorted List 1? ";
    cin >> n1;
    cout << "Enter " << n1 << " numbers in sorted order:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertEnd(list1, val);
    }

    // Input Second Sorted List
    cout << "\nHow many elements in Sorted List 2? ";
    cin >> n2;
    cout << "Enter " << n2 << " numbers in sorted order:\n";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertEnd(list2, val);
    }

    cout << "\nList 1: ";
    display(list1);
    cout << "List 2: ";
    display(list2);

    // Merge them!
    Node* mergedHead = mergeLists(list1, list2);

    cout << "\nMerged Sorted List: ";
    display(mergedHead);

    return 0;
}
