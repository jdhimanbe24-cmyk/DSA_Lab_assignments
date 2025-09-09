// delete all the vowels from a string
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    string result="";
    for(char c: s) if(!isVowel(c)) result+=c;
    cout << "Without vowels: " << result << endl;
}

