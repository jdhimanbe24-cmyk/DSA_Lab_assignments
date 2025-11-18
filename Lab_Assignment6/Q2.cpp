// 2) Display circular list ending with head again
#include<iostream>
using namespace std;

struct Node { int data; Node* next; };

void display(Node* head) {
    if (!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data;
}

int main() {
    Node* head = new Node{20, NULL};
    head->next = new Node{100, NULL};
    head->next->next = new Node{40, NULL};
    head->next->next->next = new Node{80, NULL};
    head->next->next->next->next = new Node{60, head};

    display(head);
}
