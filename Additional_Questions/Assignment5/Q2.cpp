// 2) Reverse linked list in groups of K
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseK(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt = NULL;
    int count = 0;

    while (curr && count < k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    if (nxt) head->next = reverseK(nxt, k);
    return prev;
}

void display(Node* h) {
    while (h) { cout << h->data; if (h->next) cout << "->"; h = h->next; }
}

int main() {
    Node* head = new Node{1,new Node{2,new Node{3,new Node{4,new Node{5,new Node{6,new Node{7,new Node{8,new Node{9,NULL}}}}}}}}};
    int k = 3;

    head = reverseK(head, k);
    display(head);
}
