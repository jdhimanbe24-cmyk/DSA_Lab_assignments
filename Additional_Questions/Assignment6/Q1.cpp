// Q1: Split a Circular Linked List into Two Halves
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

void splitList(Node* head, Node*& h1, Node*& h2) {
    if (!head) return;

    Node *slow=head, *fast=head;
    while (fast->next!=head && fast->next->next!=head) {
        fast=fast->next->next;
        slow=slow->next;
    }
    if (fast->next->next==head) fast=fast->next;

    h1 = head;
    if (head->next!=head) h2 = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

void printCLL(Node* head) {
    Node* t=head;
    if(!head) return;
    do {
        cout<<t->data<<" ";
        t=t->next;
    } while(t!=head);
}

int main(){
    Node* head=new Node(10);
    head->next=new Node(4);
    head->next->next=new Node(9);
    head->next->next->next=head;

    Node* h1=NULL; Node* h2=NULL;
    splitList(head,h1,h2);

    printCLL(h1); cout<<"\n";
    printCLL(h2);
}
