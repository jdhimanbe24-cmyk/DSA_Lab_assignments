// 5) Add two polynomials represented as linked lists
#include<iostream>
using namespace std;

struct Node {
    int coeff, pow;
    Node* next;
};

Node* insert(Node* head, int c, int p) {
    if (!head) return new Node{c,p,NULL};
    Node* t = head;
    while (t->next) t = t->next;
    t->next = new Node{c,p,NULL};
    return head;
}

Node* addPoly(Node* a, Node* b) {
    Node* res = NULL;

    while (a && b) {
        if (a->pow == b->pow) {
            res = insert(res, a->coeff + b->coeff, a->pow);
            a = a->next; b = b->next;
        } else if (a->pow > b->pow) {
            res = insert(res, a->coeff, a->pow);
            a = a->next;
        } else {
            res = insert(res, b->coeff, b->pow);
            b = b->next;
        }
    }

    while (a) { res = insert(res, a->coeff, a->pow); a = a->next; }
    while (b) { res = insert(res, b->coeff, b->pow); b = b->next; }

    return res;
}

void display(Node* h) {
    cout << "[";
    while (h) {
        cout << "[" << h->coeff << ", " << h->pow << "]";
        if (h->next) cout << ", ";
        h = h->next;
    }
    cout << "]";
}

int main() {
    Node* list1 = NULL;
    list1 = insert(list1, 5, 2);
    list1 = insert(list1, 4, 1);
    list1 = insert(list1, 2, 0);

    Node* list2 = NULL;
    list2 = insert(list2, 5, 1);
    list2 = insert(list2, 5, 0);

    Node* ans = addPoly(list1, list2);
    display(ans);
}
