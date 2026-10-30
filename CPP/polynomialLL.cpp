#include <iostream>
using namespace std;

// 1. Define the Polynomial Node structure (No classes used)
struct Node {
    int coeff;
    int exp;
    Node* next;
};

// --- MASTER FUNCTION: Inserts in order & combines like terms ---
void insertTerm(Node*& head, int c, int e) {
    if (c == 0) return; // Ignore zero terms

    Node* newNode = new Node();
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    // 1. If list is empty OR new exponent is larger than head's exponent
    if (head == NULL || e > head->exp) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // 2. Walk forward as long as the next exponent is >= our new exponent
    Node* temp = head;
    while (temp->next != NULL && temp->next->exp >= e) {
        temp = temp->next;
    }

    // 3. If a term with the SAME exponent already exists, just add coefficients!
    if (temp->exp == e) {
        temp->coeff = temp->coeff + c;
        delete newNode; // Don't need the extra node
    } 
    // 4. Otherwise, link the new term right after temp
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// --- Helper function to read a Polynomial from the user ---
void createPoly(Node*& head) {
    int n, c, e;
    cout << "How many terms in this polynomial? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter coefficient and exponent for term " << i << ": ";
        cin >> c >> e;
        insertTerm(head, c, e);
    }
}

// --- 1. POLYNOMIAL ADDITION ---
Node* addPoly(Node* p1, Node* p2) {
    Node* sum = NULL;

    // Insert all terms of Polynomial 1 into sum
    Node* temp1 = p1;
    while (temp1 != NULL) {
        insertTerm(sum, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Insert all terms of Polynomial 2 into sum 
    // (insertTerm automatically adds coefficients if exponents match!)
    Node* temp2 = p2;
    while (temp2 != NULL) {
        insertTerm(sum, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return sum;
}

// --- 2. POLYNOMIAL MULTIPLICATION ---
Node* multiplyPoly(Node* p1, Node* p2) {
    Node* prod = NULL;

    // Multiply every term of p1 with every term of p2
    for (Node* i = p1; i != NULL; i = i->next) {
        for (Node* j = p2; j != NULL; j = j->next) {
            int newCoeff = i->coeff * j->coeff; // Multiply coefficients
            int newExp = i->exp + j->exp;       // Add exponents
            
            // insertTerm automatically combines matching exponents!
            insertTerm(prod, newCoeff, newExp);
        }
    }

    return prod;
}

// --- DISPLAY FUNCTION ---
void display(Node* head) {
    if (head == NULL) {
        cout << "0\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next != NULL && temp->next->coeff >= 0) {
            cout << " + ";
        } else if (temp->next != NULL) {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// --- MAIN FUNCTION ---
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    cout << "--- Enter First Polynomial ---\n";
    createPoly(poly1);

    cout << "\n--- Enter Second Polynomial ---\n";
    createPoly(poly2);

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    // Perform Addition
    Node* sum = addPoly(poly1, poly2);
    cout << "\nAddition Result:       ";
    display(sum);

    // Perform Multiplication
    Node* prod = multiplyPoly(poly1, poly2);
    cout << "Multiplication Result: ";
    display(prod);

    return 0;
}
