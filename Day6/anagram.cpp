// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// What is Anagram ?
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.


#include<iostream>
#include<string>

using namespace std;

bool isAnagram(string s, string t);

int main(void){
    string s = "anagram";
    string t = "nagaram";

    bool retVal = isAnagram(s, t);

    if(retVal){
        cout << "Yes the given strings are anagram";
    }else{
        cout << "No the given strings are not anagram";
    }

    return EXIT_SUCCESS;
}

bool isAnagram(string s, string t){
    int n = s.length();
    int m = t.length();

    if(n != m) return false;

    int freq[26] = {0};
    
    for(char c : s) freq[c - 'a']++;
    for(char c : t) freq[c - 'a']--;

    for(int i = 0; i != 26; ++i){
        if(freq[i] != 0){
            return false;
        }
    }
    
    return true;
}
