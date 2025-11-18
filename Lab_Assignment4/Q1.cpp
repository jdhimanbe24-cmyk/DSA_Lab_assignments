// QUESTION 1: SIMPLE QUEUE (MENU DRIVEN)

#include<iostream>
using namespace std;

#define SIZE 50

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if(isFull()) { cout<<"Queue Full\n"; return; }
        if(isEmpty()) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if(isEmpty()) { cout<<"Queue Empty\n"; return; }
        cout<<"Deleted: "<<arr[front]<<'\n';
        if(front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if(isEmpty()) cout<<"Empty\n";
        else cout<<"Front: "<<arr[front]<<'\n';
    }

    void display() {
        if(isEmpty()) { cout<<"Empty\n"; return; }
        for(int i = front; i <= rear; i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main() {
    Queue q;
    int choice, x;

    while(true) {
        cout<<"\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin>>choice;

        switch(choice) {
            case 1: cin>>x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: return 0;
        }
    }
}
