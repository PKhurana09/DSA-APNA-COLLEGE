// Given a string s, find the length of the longest substring without duplicate characters.

#include<iostream>
#include<unordered_set>
#include<limits.h>

using namespace std;

int lengthOfLongestSubstring(string s);

int main(void){
    cout << "The length of longest substring is: " << lengthOfLongestSubstring("PRANAV");

    return EXIT_SUCCESS;
}

int lengthOfLongestSubstring(string s){
    if(s.empty()) return 0;
    int n = s.length();
    unordered_set<char> ans;
    int maxAns = 0;
    int left = 0; 
    int right = 0;

    while(right < n){
        if(ans.find(s[right]) == ans.end()){
            ans.insert(s[right]);
            maxAns = max(maxAns, right - left + 1);
            ++right; // Expand the window
        }else{
            ans.erase(s[left]);
            ++left; // Shrink the window
        }
    }
    return maxAns;
}