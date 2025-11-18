// Q5: Convert 2D Matrix into 4 Pointer DLL (next, prev, up, down)
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int d){ data=d; next=prev=up=down=NULL; }
};

Node* convert(int a[3][3]){
    Node* mat[3][3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            mat[i][j]=new Node(a[i][j]);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j<2) mat[i][j]->next = mat[i][j+1];
            if(j>0) mat[i][j]->prev = mat[i][j-1];
            if(i<2) mat[i][j]->down = mat[i+1][j];
            if(i>0) mat[i][j]->up   = mat[i-1][j];
        }
    }
    return mat[0][0];
}

int main(){
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    Node* head = convert(a);

    Node* r=head;
    while(r){
        Node* c=r;
        while(c){
            cout<<c->data<<" ";
            c=c->next;
        }
        cout<<"\n";
        r=r->down;
    }
}
