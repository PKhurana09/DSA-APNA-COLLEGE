// Given an integer array nums, find the subarray with the largest sum and return its sum.
// Example : Leetcode Streak
// Rahul loves coding and wants to solve problems on LeetCode every day to improve his skills. Some days he solves many problems (+points), while on tough days, he struggles or skips (-points). To find his best streak, he uses Kadane’s algorithm, which helps track the highest consecutive score. Instead of checking all days manually, the algorithm smartly continues a streak or starts fresh when needed.


#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int maxSubArray(vector<int>& nums);

int main(void){
    vector<int> retVal = {3, -4, 5, 4, -1, 7, -8};

    cout << "Maximum subarray sum for the give array is: " << maxSubArray(retVal);
    
    return EXIT_SUCCESS;
}

int maxSubArray(vector<int>& nums){
    int currSum = 0;
    int maxSum = INT_MIN;
    int n = nums.size();

    for(int i = 0; i != n; ++i){
        currSum += nums[i];
        maxSum = max(currSum, maxSum);

        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}
