#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Global head pointer starts as NULL (empty list)
Node* head = NULL;

// --- INSERTION AT 3 POSITIONS ---

// 1. Insert at Beginning
void insertBeg(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode; // Connect old head back to newNode
    }
    head = newNode; // Move head to newNode
    cout << "Inserted at beginning.\n";
}

// 2. Insert at End
void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty, newNode becomes the head
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        cout << "Inserted at end.\n";
        return;
    }

    // last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node and newNode together
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted at end.\n";
}

// 3. Insert at a Specific Position (1-based index)
void insertPos(int val, int pos) {
    if (pos == 1) {
        insertBeg(val);
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    // Walk to the node JUST BEFORE the target position (pos - 1)
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    // 4-Pointer Connection for inserting in the middle
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    cout << "Inserted at position " << pos << ".\n";
}

// --- DELETION AT 3 POSITIONS ---

// 4. Delete from Beginning
void deleteBeg() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next; // Move head to the 2nd node

    if (head != NULL) {
        head->prev = NULL; // Remove link to old head
    }

    delete temp;
    cout << "Deleted from beginning.\n";
}

// 5. Delete from End
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // If there is only 1 node in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted from end.\n";
        return;
    }

    // Walk all the way to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Tell the second-to-last node that nothing comes after it now
    temp->prev->next = NULL;
    delete temp;
    cout << "Deleted from end.\n";
}

// 6. Delete from a Specific Position (1-based index)
void deletePos(int pos) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    //  node we want to delete
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    // Bypass 'temp' by connecting its left neighbor to its right neighbor
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted from position " << pos << ".\n";
}

// --- DISPLAY FUNCTION ---
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    cout << "NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// --- MAIN MENU ---
int main() {
    int choice, val, pos;

    while (true) {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert Beginning  2. Insert End  3. Insert Position\n";
        cout << "4. Delete Beginning  5. Delete End  6. Delete Position\n";
        cout << "7. Display           8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: "; cin >> val;
            insertBeg(val);
        } else if (choice == 2) {
            cout << "Enter value: "; cin >> val;
            insertEnd(val);
        } else if (choice == 3) {
            cout << "Enter value and position: "; cin >> val >> pos;
            insertPos(val, pos);
        } else if (choice == 4) {
            deleteBeg();
        } else if (choice == 5) {
            deleteEnd();
        } else if (choice == 6) {
            cout << "Enter position to delete: "; cin >> pos;
            deletePos(pos);
        } else if (choice == 7) {
            display();
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
