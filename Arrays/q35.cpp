// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);

int main(void){
    vector<int> nums = {1, 3, 5, 6};

    cout << "The given target should be inserted at: " << searchInsert(nums, 0);
    return EXIT_SUCCESS;
}

int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int st = 0;
    int end = n - 1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    // nums.insert(nums.begin() + st, target);
    return st;
}