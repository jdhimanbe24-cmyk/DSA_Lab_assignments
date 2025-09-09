// to find transpose of a sparse matrix assuming matrix is represented using triplets.
#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, n;   // rows, cols, non-zero count
    Element *ele;        // dynamic array of triplets
};

void read(Sparse &s) {
    cout << "Enter rows, cols, number of non-zero elements: ";
    cin >> s.rows >> s.cols >> s.n;
    s.ele = new Element[s.n];
    cout << "Enter row col value for each non-zero element:\n";
    for(int i=0;i<s.n;i++)
        cin >> s.ele[i].row >> s.ele[i].col >> s.ele[i].val;
}

void display(const Sparse &s) {
    int k=0;
    for(int i=0;i<s.rows;i++) {
        for(int j=0;j<s.cols;j++) {
            if(k<s.n && s.ele[k].row==i && s.ele[k].col==j)
                cout << s.ele[k++].val << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

Sparse transpose(const Sparse &s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.n = s.n;
    t.ele = new Element[t.n];
    for(int i=0;i<s.n;i++) {
        t.ele[i].row = s.ele[i].col;
        t.ele[i].col = s.ele[i].row;
        t.ele[i].val = s.ele[i].val;
    }
    return t;
}

Sparse add(const Sparse &s1, const Sparse &s2) {
    if(s1.rows!=s2.rows || s1.cols!=s2.cols) {
        cout << "Matrix dimensions mismatch!\n";
        return {0,0,0,nullptr};
    }

    Sparse sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.ele = new Element[s1.n + s2.n];

    int i=0,j=0,k=0;
    while(i<s1.n && j<s2.n) {
        if(s1.ele[i].row < s2.ele[j].row ||
          (s1.ele[i].row==s2.ele[j].row && s1.ele[i].col < s2.ele[j].col))
            sum.ele[k++] = s1.ele[i++];
        else if(s2.ele[j].row < s1.ele[i].row ||
               (s2.ele[j].row==s1.ele[i].row && s2.ele[j].col < s1.ele[i].col))
            sum.ele[k++] = s2.ele[j++];
        else {
            sum.ele[k] = s1.ele[i];
            sum.ele[k++].val = s1.ele[i++].val + s2.ele[j++].val;
        }
    }
    while(i<s1.n) sum.ele[k++] = s1.ele[i++];
    while(j<s2.n) sum.ele[k++] = s2.ele[j++];
    sum.n = k;
    return sum;
}

Sparse multiply(const Sparse &s1, const Sparse &s2) {
    if(s1.cols != s2.rows) {
        cout << "Matrix dimensions mismatch!\n";
        return {0,0,0,nullptr};
    }

    Sparse prod;
    prod.rows = s1.rows;
    prod.cols = s2.cols;
    prod.ele = new Element[s1.n * s2.n]; // worst case
    prod.n = 0;

    for(int i=0;i<s1.n;i++) {
        for(int j=0;j<s2.n;j++) {
            if(s1.ele[i].col == s2.ele[j].row) {
                // Multiply and add
                int r = s1.ele[i].row;
                int c = s2.ele[j].col;
                int v = s1.ele[i].val * s2.ele[j].val;

                // Check if already present
                bool found=false;
                for(int k=0;k<prod.n;k++) {
                    if(prod.ele[k].row==r && prod.ele[k].col==c) {
                        prod.ele[k].val += v;
                        found=true;
                        break;
                    }
                }
                if(!found) prod.ele[prod.n++] = {r,c,v};
            }
        }
    }
    return prod;
}

int main() {
    Sparse A,B;
    cout << "Enter first matrix:\n";
    read(A);
    cout << "Enter second matrix:\n";
    read(B);

    cout << "\nMatrix A:\n"; display(A);
    cout << "\nMatrix B:\n"; display(B);

    cout << "\nTranspose of A:\n"; display(transpose(A));

    cout << "\nA + B:\n"; display(add(A,B));

    cout << "\nA * B:\n"; display(multiply(A,B));

    return 0;

}
