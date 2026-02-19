// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target);

int main(void){
    vector<int> retVal = {-1, 0, 3, 5, 9, 12};

    cout << "The index of the give target is: " << search(retVal, 3);
    
    return EXIT_SUCCESS;
}

int search(vector<int>& nums, int target){
    int n = nums.size();
    int st = 0;
    int end = n - 1;

    while(st <= end){
        int mid = st + (end -st)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return -1;
}