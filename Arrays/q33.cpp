// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target);

int main(void){

    return EXIT_SUCCESS;
}

int search(vector<int>& nums, int target){
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[st] <= nums[mid]){ // left part is sorted
            if(nums[mid] > target && target >= nums[st]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{ // right part is sorted
            if(target <= nums[end] && target > nums[mid]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}