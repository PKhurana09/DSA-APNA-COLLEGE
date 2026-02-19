// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>

using namespace std;

int leftSearch(vector<int>& nums, int target);
int rightSearch(vector<int>& nums, int target);
vector<int> searchRange(vector<int>& nums, int target);

int main(void){
    vector<int> check = {5, 7, 7, 8, 8, 10};
    vector<int> retVal = searchRange(check, 8);

    int n = retVal.size();

    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}

int leftSearch(vector<int>& nums, int target){
    int st = 0, end = nums.size() - 1;
    int ans = -1;
        
    while (st <= end) {
        int mid = st + (end - st) / 2;
            
        if (nums[mid] == target) {
            ans = mid;          // potential answer
            end = mid - 1;      // move left to find earlier occurrence
        }else if (nums[mid] < target) {
            st = mid + 1;
        }else {
            end = mid - 1;
        }
    }    
    return ans;
}

int rightSearch(vector<int>& nums, int target){
    int st = 0, end = nums.size() - 1;
    int ans = -1;
        
    while (st <= end) {
        int mid = st + (end - st) / 2;   
        if (nums[mid] == target) {
            ans = mid;          // potential answer
            st = mid + 1;      // move left to find earlier occurrence
        }else if (nums[mid] < target) {
            st = mid + 1;
        }else {
            end = mid - 1;
        }
    }    
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target){
    int first = leftSearch(nums, target);
    int last = rightSearch(nums, target);
        
    return {first, last};
}
