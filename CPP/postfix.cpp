#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define max 100
int stack[max];
char postfix[max];
int top = -1;

int posteval();
void push(int);
int pop();
int empty();

int main() {
    cout << "enter the postfix expression" << endl;
    cin >> postfix;
    
    cout << "postfix expression" << endl;
    cout << postfix << endl;
    
    int result = posteval();
    cout << "result " << result << endl;
    
    return 0;
}

int posteval() {
    int i;
    int a, b;
    
    for(i = 0; i < strlen(postfix); i++) {
        // If the character is a digit, convert it to an integer and push it
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } 
        else {
            a = pop(); // pop topmost element
            b = pop(); // pop second topmost element
            
            switch(postfix[i]) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
                case '^': push(pow(b, a)); break;
            }
        }
    }
    return pop();
}

void push(int t) {
    if (top == max - 1) {
        cout << "overflow" << endl;
        return;
    }
    top++;
    stack[top] = t;
}

int pop() {
    int t;
    if (top == -1) {
        cout << "underflow" << endl; 
        return 0; // Returning 0 
    }
    t = stack[top];
    top--;
    return t;
}

int empty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}
