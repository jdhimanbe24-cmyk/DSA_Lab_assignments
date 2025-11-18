// Q3: Reverse Doubly Linked List in Groups of K
#include<iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d){ data=d; prev=next=NULL; }
};

DNode* reverseK(DNode* head,int k){
    if(!head) return NULL;

    DNode* curr=head;
    DNode* prev=NULL;
    int cnt=0;

    while(curr && cnt<k){
        DNode* nextNode=curr->next;
        curr->next=prev;
        curr->prev=nextNode;
        prev=curr;
        curr=nextNode;
        cnt++;
    }

    if(curr) {
        head->next = reverseK(curr,k);
        if(head->next) head->next->prev=head;
    }

    return prev;
}

void printDLL(DNode* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
}

int main(){
    DNode* head=new DNode(1);
    head->next=new DNode(2); head->next->prev=head;
    head->next->next=new DNode(3); head->next->next->prev=head->next;
    head->next->next->next=new DNode(4); head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new DNode(5); head->next->next->next->next->prev=head->next->next->next;
    head->next->next->next->next->next=new DNode(6); head->next->next->next->next->next->prev=head->next->next->next->next;

    head = reverseK(head,2);
    printDLL(head);
}
