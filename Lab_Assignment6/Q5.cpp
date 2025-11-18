// 5) Check if linked list is circular or not
#include<iostream>
using namespace std;

struct Node { 
    int data; 
    Node* next; 
};

bool isCircular(Node* head) {
    if (!head) return false;

    Node* t = head->next;
    while (t && t != head) {
        t = t->next;
    }
    return t == head;
}

int main() {
    Node* a = new Node{2, 
                new Node{4, 
                    new Node{6, 
                        new Node{7, 
                            new Node{5, NULL}
                        }
                    }
                }
            };

    // make it circular
    Node* tail = a;
    while (tail->next) tail = tail->next;
    tail->next = a;

    cout << (isCircular(a) ? "True" : "False");
    return 0;
}


