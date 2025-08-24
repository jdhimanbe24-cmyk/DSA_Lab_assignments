#include <iostream>
using namespace std;

int main() {
    int r,c;
    cout << "Enter rows & cols: ";
    cin >> r >> c;
    int A[r][c];
    cout << "Enter matrix:\n";
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++) cin >> A[i][j];

    cout << "Row sums:\n";
    for (int i=0;i<r;i++) {
        int sum=0;
        for (int j=0;j<c;j++) sum+=A[i][j];
        cout << "Row " << i << ": " << sum << endl;
    }

    cout << "Column sums:\n";
    for (int j=0;j<c;j++) {
        int sum=0;
        for (int i=0;i<r;i++) sum+=A[i][j];
        cout << "Col " << j << ": " << sum << endl;
    }
    return 0;
}