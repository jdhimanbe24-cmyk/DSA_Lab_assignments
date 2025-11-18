// 2) Count and delete all occurrences of key
#include<iostream>
using namespace std;

struct Node { int data; Node* next; };

Node* deleteAll(Node* head, int key, int &count) {
    while (head && head->data == key) {
        Node* t = head; head = head->next; delete t; count++;
    }
    if (!head) return head;

    Node* temp = head;
    while (temp->next) {
        if (temp->next->data == key) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
            count++;
        } else temp = temp->next;
    }
    return head;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{1,new Node{2,new Node{1,new Node{2,new Node{1,new Node{3,new Node{1,NULL}}}}}}};
    int key = 1, count = 0;
    head = deleteAll(head, key, count);
    cout << "Count: " << count << " , Updated Linked List: ";
    display(head);
}
