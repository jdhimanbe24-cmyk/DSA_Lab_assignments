// 1) Doubly Linked List Menu Driven
#include<iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

void displayD(DNode* h) {
    while (h) { cout << h->data << " "; h = h->next; }
}

DNode* insertFrontD(DNode* head, int val) {
    DNode* n = new DNode{val, head, NULL};
    if (head) head->prev = n;
    return n;
}

DNode* insertEndD(DNode* head, int val) {
    DNode* n = new DNode{val, NULL, NULL};
    if (!head) return n;
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

DNode* insertAfterD(DNode* head, int key, int val) {
    DNode* t = head;
    while (t) {
        if (t->data == key) {
            DNode* n = new DNode{val, t->next, t};
            if (t->next) t->next->prev = n;
            t->next = n;
            return head;
        }
        t = t->next;
    }
    return head;
}

DNode* insertBeforeD(DNode* head, int key, int val) {
    if (!head) return head;
    if (head->data == key) return insertFrontD(head, val);

    DNode* t = head;
    while (t) {
        if (t->data == key) {
            DNode* n = new DNode{val, t, t->prev};
            t->prev->next = n;
            t->prev = n;
            return head;
        }
        t = t->next;
    }
    return head;
}

DNode* deleteD(DNode* head, int key) {
    if (!head) return head;

    if (head->data == key) {
        DNode* t = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete t;
        return head;
    }

    DNode* t = head;
    while (t) {
        if (t->data == key) {
            if (t->prev) t->prev->next = t->next;
            if (t->next) t->next->prev = t->prev;
            delete t;
            return head;
        }
        t = t->next;
    }
    return head;
}

int searchD(DNode* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

int main() {
    DNode* head = NULL;
    int ch, val, key;
    do {
        cin >> ch;
        if (ch == 1) { cin >> val; head = insertFrontD(head,val); }
        else if (ch == 2) { cin >> val; head = insertEndD(head,val); }
        else if (ch == 3) { cin >> key >> val; head = insertAfterD(head,key,val); }
        else if (ch == 4) { cin >> key >> val; head = insertBeforeD(head,key,val); }
        else if (ch == 5) { cin >> key; head = deleteD(head,key); }
        else if (ch == 6) { cin >> key; cout << searchD(head,key) << endl; }
        else if (ch == 7) displayD(head);
    } while (ch != 0);
}
