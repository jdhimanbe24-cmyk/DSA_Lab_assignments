// QUESTION 2: CIRCULAR QUEUE (MENU DRIVEN)

#include<iostream>
using namespace std;

#define SIZE 50

class CQueue {
    int arr[SIZE];
    int front, rear;

public:
    CQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear + 1) % SIZE == front; }

    void enqueue(int x) {
        if(isFull()) { cout<<"Full\n"; return; }
        if(isEmpty()) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if(isEmpty()) { cout<<"Empty\n"; return; }
        cout<<"Deleted: "<<arr[front]<<'\n';
        if(front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void peek() {
        if(isEmpty()) cout<<"Empty\n";
        else cout<<"Front: "<<arr[front]<<'\n';
    }

    void display() {
        if(isEmpty()) { cout<<"Empty\n"; return; }
        int i = front;
        while(true) {
            cout<<arr[i]<<" ";
            if(i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout<<"\n";
    }
};

int main() {
    CQueue q;
    int ch, x;

    while(true) {
        cout<<"\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin>>ch;

        switch(ch) {
            case 1: cin>>x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: return 0;
        }
    }
}
