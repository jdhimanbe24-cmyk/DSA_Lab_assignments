// Check balanced parentheses
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
    bool isEmpty() { return top == -1; }
    char peek() { return arr[top]; }
};

bool isMatching(char open, char close) {
    return (open=='(' && close==')') || 
           (open=='[' && close==']') || 
           (open=='{' && close=='}');
}

bool checkBalanced(string expr) {
    Stack st;
    for (char c : expr) {
        if (c=='(' || c=='[' || c=='{') st.push(c);
        else if (c==')' || c==']' || c=='}') {
            if (st.isEmpty() || !isMatching(st.pop(), c)) return false;
        }
    }
    return st.isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (checkBalanced(expr)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
