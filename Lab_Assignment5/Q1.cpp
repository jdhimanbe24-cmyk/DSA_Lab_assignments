//  menu driven program for Singly Linked List.
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Utility Functions
Node* insertBegin(Node* head, int val) {
    Node* t = new Node{val, head};
    return t;
}

Node* insertEnd(Node* head, int val) {
    Node* t = new Node{val, NULL};
    if (!head) return t;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = t;
    return head;
}

Node* insertBefore(Node* head, int key, int val) {
    if (!head) return head;
    if (head->data == key) return insertBegin(head, val);
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        Node* n = new Node{val, temp->next};
        temp->next = n;
    }
    return head;
}

Node* insertAfter(Node* head, int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (temp) {
        Node* n = new Node{val, temp->next};
        temp->next = n;
    }
    return head;
}

Node* deleteBegin(Node* head) {
    if (!head) return head;
    Node* t = head;
    head = head->next;
    delete t;
    return head;
}

Node* deleteEnd(Node* head) {
    if (!head) return head;
    if (!head->next) { delete head; return NULL; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* deleteSpecific(Node* head, int key) {
    if (!head) return head;
    if (head->data == key) return deleteBegin(head);
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (temp->next) {
        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }
    return head;
}

int search(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) return pos;
        pos++; head = head->next;
    }
    return -1;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "\n";
}

// ------------------ 1) MENU DRIVEN SINGLY LINKED LIST ------------------
int main() {
    Node* head = NULL;
    int choice, val, key;

    do {
        cout << "\n1.Insert Begin\n2.Insert End\n3.Insert Before\n4.Insert After\n";
        cout << "5.Delete Begin\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;

        switch(choice) {
            case 1:
                cin >> val;
                head = insertBegin(head, val);
                break;
            case 2:
                cin >> val;
                head = insertEnd(head, val);
                break;
            case 3:
                cin >> key >> val;
                head = insertBefore(head, key, val);
                break;
            case 4:
                cin >> key >> val;
                head = insertAfter(head, key, val);
                break;
            case 5:
                head = deleteBegin(head);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                cin >> key;
                head = deleteSpecific(head, key);
                break;
            case 8:
                cin >> key;
                cout << search(head, key) << "\n";
                break;
            case 9:
                display(head);
                break;
        }
    } while (choice != 10);

    return 0;
}
