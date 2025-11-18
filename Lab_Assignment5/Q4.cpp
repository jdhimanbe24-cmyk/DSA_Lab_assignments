// 4) Reverse Linked List
#include<iostream>
using namespace std;

struct Node { int data; Node* next; };

void display(Node* h) {
    while (h) { cout << h->data; if (h->next) cout << "->"; h = h->next; }
}

int main() {
    Node* head = new Node{1,new Node{2,new Node{3,new Node{4,NULL}}}};
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;
    display(head);
}
