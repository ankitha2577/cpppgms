#include <iostream>
using namespace std;

struct Node {
    string data; 
    Node* prev;
    Node* next;
};

Node* head = NULL;

// 2. Insert at End 
void insertEnd(string val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// 3. Find the Missile (Linear Search)
void findMissile(string target) {
    if (head == NULL) {
        cout << "The area is empty! No nodes to search.\n";
        return;
    }

    Node* temp = head;
    int pos = 1; // Track the position

    // Walk through the list looking for the target
    while (temp != NULL) {
        if (temp->data == target) {
            cout <<  target << " found at position " << pos << "!\n";
            return; // Stop searching once we find it
        }
        temp = temp->next;
        pos++;
    }

    // If the loop finishes and we didn't return, it's not there
    cout << "Clear! No " << target << " found in the list.\n";
}

// 4. Display the List
void display() {
    Node* temp = head;
   
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int n;
    string item, target;

    cout << "How many items in the linked list? ";
    cin >> n;

    cout << "Enter " << n << " items (e.g., Decoy, Base, Missile):\n";
    for (int i = 0; i < n; i++) {
        cin >> item;
        insertEnd(item);
    }

    display();

    cout << "\nEnter the name of the missile you want to find: ";
    cin >> target;

    findMissile(target);

    return 0;
}
