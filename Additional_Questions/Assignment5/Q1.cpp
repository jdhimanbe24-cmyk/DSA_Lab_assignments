// 1) Intersection of two linked lists (Y-shaped)
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int length(Node* head) {
    int c = 0;
    while (head) head = head->next, c++;
    return c;
}

Node* intersection(Node* a, Node* b) {
    int L1 = length(a), L2 = length(b);
    int d = abs(L1 - L2);

    if (L1 > L2) while (d--) a = a->next;
    else while (d--) b = b->next;

    while (a && b) {
        if (a == b) return a;
        a = a->next;
        b = b->next;
    }
    return NULL;
}

int main() {
    Node* common = new Node{8, new Node{5, NULL}};
    Node* A = new Node{4, new Node{1, common}};
    Node* B = new Node{5, new Node{6, new Node{1, common}}};

    Node* ans = intersection(A, B);
    if (ans) cout << "Intersected at " << ans->data;
    else cout << "No intersection";
}
