// Infix to postfix conversion
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    if (c=='^') return 3;
    return -1;
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.isEmpty() && st.peek()!='(') postfix += st.pop();
            st.pop(); // remove '('
        } else {
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()))
                postfix += st.pop();
            st.push(c);
        }
    }
    while (!st.isEmpty()) postfix += st.pop();
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
