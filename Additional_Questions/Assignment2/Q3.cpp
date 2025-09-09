// String Anagrams
#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    int freq1[26] = {0}, freq2[26] = {0};
    for (char c : s1) freq1[c - 'a']++;
    for (char c : s2) freq2[c - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (areAnagrams(s1, s2)) cout << "Anagram pair\n";
    else cout << "Not an anagram pair\n";
    return 0;
}
