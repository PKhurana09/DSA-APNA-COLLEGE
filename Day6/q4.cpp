// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

#include<iostream>
#include<string>
#include <cstddef>

using namespace std;

string removeOccurrences(string s, string part);

int main(void){
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(s, part) << endl;

    return EXIT_SUCCESS;
}

string removeOccurrences(string s, string part){
    int m = part.length();
    size_t pos;

    while((pos = s.find(part)) != string::npos){
        s.erase(pos, m);
    }

    return s;
}
