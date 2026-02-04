// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".


#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main(void){

    return EXIT_SUCCESS;
}

string longestCommonPrefix(vector<string>& strs){
    if(strs.empty()) return "";

    int n = strs.size();

    for(int i = 0; i != strs[0].size(); ++i){
        char ch = strs[0][i];
        for(int j = 1; j != n; ++j){
            // If index out of range or mismatch is found
            if(i >= strs[j].size() || ch != strs[j][i]){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}
