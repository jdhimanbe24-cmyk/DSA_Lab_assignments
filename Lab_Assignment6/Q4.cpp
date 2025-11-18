// 4) Palindrome doubly linked list
#include<iostream>
using namespace std;

struct Node { char data; Node* next; Node* prev; };

bool isPal(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r', new Node{'a', new Node{'d', new Node{'a', new Node{'r', NULL, NULL}, NULL}, NULL}, NULL}, NULL};
    a->next->prev = a;
    a->next->next->prev = a->next;
    a->next->next->next->prev = a->next->next;
    a->next->next->next->next->prev = a->next->next->next;

    cout << (isPal(a) ? "True" : "False");
}
