// 4) Rotate linked list left by k
#include<iostream>
using namespace std;

struct Node { int data; Node* next; };

void display(Node* h) {
    while (h) { cout << h->data; if (h->next) cout << "->"; h = h->next; }
}

Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head;

    Node* temp = head;
    int len = 1;
    while (temp->next) temp = temp->next, len++;

    k %= len;
    if (k == 0) return head;

    temp->next = head;

    Node* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    Node* head = new Node{1,new Node{2,new Node{3,new Node{4,new Node{5,new Node{6,NULL}}}}}};
    int k = 4;

    head = rotate(head, k);
    display(head);
}
