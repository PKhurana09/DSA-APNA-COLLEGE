// Given a string s, find the length of the longest substring without duplicate characters.


#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s);

int main(void){
    string s = "bbbb";

    cout << "The longest substring without any repetitive character is: " << lengthOfLongestSubstring(s);

    return EXIT_SUCCESS;
}

int lengthOfLongestSubstring(string s){
    unordered_set<char> st;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++) {

        // Shrink window until duplicate is removed
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        // Expand window
        st.insert(s[right]);

        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}