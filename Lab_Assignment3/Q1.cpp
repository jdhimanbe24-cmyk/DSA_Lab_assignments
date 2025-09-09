// Stack operations using array
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) cout << "Stack Overflow!\n";
        else arr[++top] = x;
    }

    void pop() {
        if (isEmpty()) cout << "Stack Underflow!\n";
        else top--;
    }

    void peek() {
        if (isEmpty()) cout << "Stack is empty!\n";
        else cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Stack is empty!\n";
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack st;
    int choice, val;
    while (true) {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; st.push(val); break;
            case 2: st.pop(); break;
            case 3: cout << (st.isEmpty() ? "Stack is Empty\n" : "Not Empty\n"); break;
            case 4: cout << (st.isFull() ? "Stack is Full\n" : "Not Full\n"); break;
            case 5: st.display(); break;
            case 6: st.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
