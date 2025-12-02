// Detect loop in a linked list (using array of nodes)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){ data=d; next=NULL; }
};

bool hasCycle(Node* head) {
    Node* visited[100];
    int count=0;
    while(head!=NULL){
        for(int i=0;i<count;i++)
            if(visited[i]==head) return true;
        visited[count++]=head;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // cycle

    cout << (hasCycle(head) ? "true" : "false") << endl;
    return 0;
}
