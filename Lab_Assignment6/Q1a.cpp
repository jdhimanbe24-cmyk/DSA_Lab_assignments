// 1) Circular Linked List Menu Driven
#include<iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

void displayC(CNode* head) {
    if (!head) return;
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

CNode* insertFrontC(CNode* head, int val) {
    CNode* n = new CNode{val, NULL};
    if (!head) {
        n->next = n;
        return n;
    }
    CNode* t = head;
    while (t->next != head) t = t->next;
    n->next = head;
    t->next = n;
    return n;
}

CNode* insertEndC(CNode* head, int val) {
    CNode* n = new CNode{val, NULL};
    if (!head) {
        n->next = n;
        return n;
    }
    CNode* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
    return head;
}

CNode* insertAfterC(CNode* head, int key, int val) {
    CNode* t = head;
    if (!t) return head;
    do {
        if (t->data == key) {
            CNode* n = new CNode{val, t->next};
            t->next = n;
            return head;
        }
        t = t->next;
    } while (t != head);
    return head;
}

CNode* insertBeforeC(CNode* head, int key, int val) {
    if (!head) return head;
    if (head->data == key) return insertFrontC(head, val);

    CNode* t = head;
    do {
        if (t->next->data == key) {
            CNode* n = new CNode{val, t->next};
            t->next = n;
            return head;
        }
        t = t->next;
    } while (t != head);
    return head;
}

CNode* deleteC(CNode* head, int key) {
    if (!head) return head;

    if (head->data == key) {
        if (head->next == head) {
            delete head;
            return NULL;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = head->next;
        CNode* del = head;
        head = head->next;
        delete del;
        return head;
    }

    CNode* t = head;
    do {
        if (t->next->data == key) {
            CNode* del = t->next;
            t->next = del->next;
            delete del;
            return head;
        }
        t = t->next;
    } while (t != head);
    return head;
}

int searchC(CNode* head, int key) {
    if (!head) return -1;
    int pos = 1;
    CNode* t = head;
    do {
        if (t->data == key) return pos;
        t = t->next;
        pos++;
    } while (t != head);
    return -1;
}

int main() {
    CNode* head = NULL;
    int ch, val, key;
    do {
        cin >> ch;
        if (ch == 1) { cin >> val; head = insertFrontC(head,val); }
        else if (ch == 2) { cin >> val; head = insertEndC(head,val); }
        else if (ch == 3) { cin >> key >> val; head = insertAfterC(head,key,val); }
        else if (ch == 4) { cin >> key >> val; head = insertBeforeC(head,key,val); }
        else if (ch == 5) { cin >> key; head = deleteC(head,key); }
        else if (ch == 6) { cin >> key; cout << searchC(head,key) << endl; }
        else if (ch == 7) displayC(head);
    } while (ch != 0);
}
