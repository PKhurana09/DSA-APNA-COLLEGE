// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
// if no such substring exists, return 0.

#include<iostream>
#include<string>
#include<unordered_map>
#include<math.h>

using namespace std;

int longestSubstring(string s, int k);

int main(void){

    return EXIT_SUCCESS;
}

int longestSubstring(string s, int k){
    int n = s.size();
    if(s.size() == 0 || s.size() < k){
        return 0;
    }

    unordered_map<char, int> freq;

    // count frequency
    for(char c: s){
        freq[c]++;
    }

    // find the invalid splid character
    for(int i = 0; i != n; ++i){
        if(freq[s[i]] < k){
            int left = longestSubstring(s.substr(0, i), k);
            int right = longestSubstring(s.substr(i+1), k);

            return max(left, right);
        }
    }

    // Entire string valid
    return s.size();
}
