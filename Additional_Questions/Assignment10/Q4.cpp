// Union and Intersection of Two Linked Lists
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};


bool exists(Node* head, int val){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val) return true;
        temp=temp->next;
    }
    return false;
}


Node* addNode(Node* head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}


Node* intersection(Node* head1, Node* head2){
    Node* result = NULL;
    Node* temp = head1;
    while(temp!=NULL){
        if(exists(head2,temp->data) && !exists(result,temp->data))
            result = addNode(result,temp->data);
        temp=temp->next;
    }
    return result;
}


Node* unionList(Node* head1, Node* head2){
    Node* result = NULL;
    Node* temp = head1;
    while(temp!=NULL){
        result = addNode(result,temp->data);
        temp=temp->next;
    }
    temp = head2;
    while(temp!=NULL){
        if(!exists(result,temp->data))
            result = addNode(result,temp->data);
        temp=temp->next;
    }
    return result;
}


void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data;
        if(temp->next!=NULL) cout << " -> ";
        temp=temp->next;
    }
    cout << endl;
}

int main(){
    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);

    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    Node* inter = intersection(head1,head2);
    Node* uni = unionList(head1,head2);

    cout << "Intersection List: ";
    printList(inter);
    cout << "Union List: ";
    printList(uni);

    return 0;
}
