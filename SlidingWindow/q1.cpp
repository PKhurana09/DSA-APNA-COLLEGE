// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k);

int main(void){
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    if(containsNearbyDuplicate(nums, k)){
        cout << "TRUE"<< endl;
    }else{
        cout << "FALSE" << endl;
    }

    return EXIT_SUCCESS;
}

bool containsNearbyDuplicate(vector<int>& nums, int k){
    int n = nums.size();
    // set to store the values that are already been seen
    unordered_set<int> retVal;
    int right = 0;
    int left = 0;

    while(right < n){
        if(retVal.find(nums[right]) == retVal.end()){
            retVal.insert(nums[right]);
            cout << left << " " << right << " " << right - left << endl;
            ++right;
        }else{

            if(right - left <= k){
                return true;
            }
            retVal.erase(nums[left]);
            ++left;
        }
    }
    return false;
}
