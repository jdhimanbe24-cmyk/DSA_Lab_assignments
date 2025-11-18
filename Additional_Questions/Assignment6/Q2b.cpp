// Q2: Remove Even-Parity Nodes from Doubly Linked List
#include<iostream>
using namespace std;

struct DNode{
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d){ data=d; prev=next=NULL; }
};

int parity(int x){
    int c=0;
    while(x){ if(x&1) c++; x>>=1; }
    return c;
}

DNode* removeEvenParityDLL(DNode* head){
    DNode* curr=head;

    while(curr){
        if(parity(curr->data)%2==0){
            if(curr==head){
                head=head->next;
                if(head) head->prev=NULL;
                curr=head;
                continue;
            }
            if(curr->next) curr->next->prev=curr->prev;
            curr->prev->next=curr->next;
        }
        curr=curr->next;
    }
    return head;
}

void printDLL(DNode* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    DNode* head = new DNode(18);
    head->next=new DNode(15); head->next->prev=head;
    head->next->next=new DNode(8); head->next->next->prev=head->next;
    head->next->next->next=new DNode(9); head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new DNode(14); head->next->next->next->next->prev=head->next->next->next;

    head = removeEvenParityDLL(head);
    printDLL(head);
}
