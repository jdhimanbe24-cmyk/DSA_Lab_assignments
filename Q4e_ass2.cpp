#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c;
    cout << "Enter uppercase character: ";
    cin >> c;
    cout << "Lowercase: " << (char)tolower(c) << endl;
}
