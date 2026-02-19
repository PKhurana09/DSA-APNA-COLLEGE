// 153. Find Minimum in Rotated Sorted Array

#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int>& nums);

int main(void){
    vector<int> retVal = {4, 5, 6, 7, 0, 1, 2};

    cout << "The smallest integer in the given rotated array is: " << findMin(retVal);

    return EXIT_SUCCESS;
}

int findMin(vector<int>& nums){
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while(st < end){
        int mid = st + (end-st)/2;

        if(nums[mid] > nums[end]){
            st = mid + 1;
        }else{
            end = mid;
        }
    }

    return nums[st];
}
