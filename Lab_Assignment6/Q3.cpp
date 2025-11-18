// 3) Size of doubly and circular linked list
#include<iostream>
using namespace std;

struct DNode { int data; DNode* next; DNode* prev; };
struct CNode { int data; CNode* next; };

int sizeD(DNode* h) {
    int c = 0;
    while (h) c++, h = h->next;
    return c;
}

int sizeC(CNode* h) {
    if (!h) return 0;
    int c = 0;
    CNode* t = h;
    do { c++; t = t->next; } while (t != h);
    return c;
}

int main() {
    DNode* d = new DNode{1,new DNode{2,new DNode{3,NULL,NULL},NULL},NULL};
    cout << sizeD(d) << endl;

    CNode* c = new CNode{1,NULL};
    c->next = new CNode{2,NULL};
    c->next->next = new CNode{3,c};
    cout << sizeC(c);
}
