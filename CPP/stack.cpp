#include <iostream>
using namespace std;

char st[100];
int top = -1;

// 1. Simple Push
void push(char c) {
    top++;
    st[top] = c;
}

// 2. Simple Pop
char pop() {
    if (top == -1) return '#'; // Return a fake character if stack is empty
    char c = st[top];
    top--;
    return c;
}

int main() {
    string expr;
    cout << "Enter bracket expression: ";
    cin >> expr;

    // Loop through every character in the string
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If it is an OPENING bracket -> Push it
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If it is a CLOSING bracket -> Pop and check if they match
        else if (ch == ')' || ch == '}' || ch == ']') {
            char last = pop();
            
            // If they DO NOT match, it's unbalanced!
            if ((ch == ')' && last != '(') || 
                (ch == '}' && last != '{') || 
                (ch == ']' && last != '[')) {
                
                cout << "UNBALANCED\n";
                return 0; // Stop the program immediately
            }
        }
    }

    // After checking everything, the stack should be empty (top == -1)
    if (top == -1) {
        cout << "BALANCED\n";
    } else {
        cout << "UNBALANCED\n"; // Stack still has opening brackets left
    }

    return 0;
}
