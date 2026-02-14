// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

#include<iostream>
#include<vector>
#include<math.h>
#include<climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums);

int main(void){
    vector<int> retVal = {2, 3, 1, 2, 4, 3};

    cout << "The minimum number of elements required to reach the target value is: " << minSubArrayLen(7, retVal) << endl;

    return EXIT_SUCCESS;
}

int minSubArrayLen(int target, vector<int>& nums){
    int n = nums.size();
    int ans = INT_MAX;

    int left = 0;
    int right = 0;
    int sum = 0;

    while(right < n){  
        sum = sum + nums[right];
        while(sum >= target){
            ans = min(ans, right - left + 1);
            sum = sum - nums[left];
            ++left;
        }
        ++right;
    }


    if(ans != INT_MAX){
        return ans;
    }else{
        return 0;
    }
}
