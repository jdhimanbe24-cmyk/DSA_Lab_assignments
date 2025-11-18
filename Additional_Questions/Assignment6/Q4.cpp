// Q4: Correct Random Pointer in a Doubly Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int d){ data=d; next=prev=random=NULL; }
};

Node* fixRandom(Node* head){
    Node* curr=head;
    while(curr){
        if(curr->next) curr->random=curr->next;
        curr=curr->next;
    }
    return head;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2); head->next->prev=head;
    head->next->next=new Node(3); head->next->next->prev=head->next;

    fixRandom(head);

    Node* t=head;
    while(t){
        cout<<t->data<<" -> random: "<<(t->random?t->random->data:-1)<<"\n";
        t=t->next;
    }
}
