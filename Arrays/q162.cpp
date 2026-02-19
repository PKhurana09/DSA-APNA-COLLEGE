// 162. Find Peak Element

#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums);

int main(void){
    vector<int> retVal = {1, 2, 3, 1};

    cout << "The peak element in the given array is: " << findPeakElement(retVal);

    return EXIT_SUCCESS;
}

int findPeakElement(vector<int>& nums){
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(mid > 0 && mid < n - 1){
            if(nums[mid] > nums[mid+1]){
                if(nums[mid] > nums[mid -1]){
                    return mid;
                }else{
                    end = mid - 1;
                }
            }else{
                st = mid + 1;
            }
        }else if(mid == 0){
            if(nums[mid] > nums[mid + 1]){
                return mid;
            }
        }else{
            if(nums[mid] > nums[mid - 1]){
                return mid;
            }
        }
    }

    return -1;
}
