// 3) Remove loop in linked list
#include<iostream>
using namespace std;

struct Node { int data; Node* next; };

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (slow != fast) return;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

int main() {
    Node* head = new Node{1,new Node{2,new Node{3,new Node{4,new Node{5,NULL}}}}};
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);
    cout << "Loop removed";
}
