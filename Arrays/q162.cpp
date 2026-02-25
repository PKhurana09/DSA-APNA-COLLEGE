// 162. Find Peak Element

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int findPeakElement(vector<int>& nums);

int main(void){
    vector<int> retVal = {1,2,1,3,5,6,4};

    cout << "The index of the largest number is: " << findPeakElement(retVal);

    return EXIT_SUCCESS;
}

int findPeakElement(vector<int>& nums){
    int n = nums.size();
    int st = 0;
    int end = n - 1;

    nums[-1] = INT_MIN;
    nums[n] = INT_MIN;

    while( st <= end){
        int mid = st + (end - st)/2;

        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
            return mid;
        }

        if(nums[mid] < nums[mid + 1]){
            st = mid + 1;
        }

        if(nums[mid] < nums[mid - 1]){
            end = mid - 1;
        }
    }

    return -1;
}
