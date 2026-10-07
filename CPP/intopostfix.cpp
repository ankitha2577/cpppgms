#include <iostream>
#include <cstring>

using namespace std;

#define max 100
char stack[max];
char infix[max], postfix[max];
int top = -1;

void intopost();
void push(char);
char pop();
int empty();
int precedence(char);

int main() {
    int i = 0;
    
    cout << "enter the expression" << endl;
    cin >> infix; 
    
    cout << "infix expression" << endl;
    cout << infix << endl;
    
    intopost();
    
    cout << "postfix expression" << endl;
    while(postfix[i]) {
        cout << postfix[i++];
    }
    cout << endl;
    
    return 0;
}

void intopost() {
    int i, j = 0; 
    char symbol, next;
    
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        
        switch(symbol) {
            case '(': 
                push(symbol); 
                break;
            case ')':
                while((next = pop()) != '(') {
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(empty() == 0 && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol); 
                break;
            default: 
                postfix[j++] = symbol;
        }
    }
    
    while(empty() == 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int precedence(char symbol) {
    switch(symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void push(char t) {
    if (top == max - 1) {
        cout << "overflow";
        return;
    }
    top++;
    stack[top] = t;
}

char pop() {
    char t;
    if (top == -1) {
        cout << "underflow" << endl; 
        return '\0'; // Returning a null character 
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
