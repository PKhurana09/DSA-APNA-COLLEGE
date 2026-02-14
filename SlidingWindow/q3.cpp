// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.
// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s);

int main(void){

    return EXIT_SUCCESS;
}

vector<string> findRepeatedDnaSequences(string s){
    int n = s.size();
    int left = 0;
    int right = 9;
    unordered_map<string, int> freq;
    vector<string> ans;

    while(right < n){
        string s1 = s.substr(left, 10);
        if(freq.count(s1)){
            freq[s1]++;
        }else{
            freq.insert({s1, 1});
        }

        ++left;
        ++right;
    }

    for(auto& it: freq){
        if(it.second >= 2){
            ans.push_back(it.first);
        }
    }

    return ans;
}
