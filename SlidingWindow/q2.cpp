// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>

using namespace std;

int findLHS(vector<int>& nums);

int main(void){
    vector<int> retVal = {1,3,2,2,5,2,3,7};

    cout << "The answer to this question is: " << findLHS(retVal) << endl;

    return EXIT_SUCCESS;
}

int findLHS(vector<int>& nums){
    unordered_map<int, int> freq;

    // step 1 count frequencies
    for(int num: nums){
        freq[num]++;
    }

    int maxLen = 0;

    // step 2 cheack pairs (x, x + 1)
    for(auto& it: freq){
        int num = it.first;

        if(freq.count((num+1))){
            maxLen = max(maxLen, it.second + freq[num + 1]);
        }
    }
    return maxLen;
}
