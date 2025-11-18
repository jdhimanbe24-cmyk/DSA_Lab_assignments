// Q2: Remove Even-Parity Nodes from Circular Linked List
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

int parity(int x){
    int c=0;
    while(x){ if(x&1) c++; x>>=1; }
    return c;
}

Node* removeEvenParityCLL(Node* head){
    if(!head) return NULL;

    Node *curr=head, *prev=NULL;
    do{
        if(parity(curr->data)%2==0){
            if(curr==head){
                Node* t=head;
                while(t->next!=head) t=t->next;
                head=head->next;
                t->next=head;
                curr=head;
                continue;
            } else {
                prev->next=curr->next;
                curr=curr->next;
                continue;
            }
        }
        prev=curr;
        curr=curr->next;
    }while(curr!=head);
    return head;
}

void printCLL(Node* head){
    if(!head) return;
    Node* t=head;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=head);
}

int main(){
    Node* head=new Node(9);
    head->next=new Node(11);
    head->next->next=new Node(34);
    head->next->next->next=new Node(6);
    head->next->next->next->next=new Node(13);
    head->next->next->next->next->next=new Node(21);
    head->next->next->next->next->next->next=head;

    head = removeEvenParityCLL(head);
    printCLL(head);
}
