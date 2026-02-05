#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target);

int main(void){

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "index of the target is: " << search(nums, 0);

    return EXIT_SUCCESS;
}

int search(vector<int>& nums, int target){
    int n = nums.size();

    int st = 0;
    int end = n - 1;

    while(st <= end){
        int mid = st + (end- st)/2;

        if(nums[mid] == target){
            return mid;
        }

        // left side of the array is sorted
        else if(nums[st] <= nums[mid]){
            if(nums[mid] > target && target >= nums[st]){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{ // Right side of the array is sorted
            if(target <= nums[end] && nums[mid] < target){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}





// This is with the time complexity of O(N)
// int search(vector<int>& nums, int target){
//     int n = nums.size();

//     if(n == 0) return -1;

//     int smallestIndex = 0;

//     for(int i = 0; i != n - 1; ++i){
//         if(nums[i+1] < nums[i]){
//             smallestIndex = i;
//             break;
//         }
//     }

//     int st1 = 0;
//     int end1 = smallestIndex;

//     int st2 = smallestIndex + 1;
//     int end2 = n - 1;
    
//     while(st1 <= end1){
//         int mid = st1 + (end1 - st1)/2;
//         if(nums[mid] == target){
//             return mid;
//         }else if(nums[mid] > target){
//             end1 = mid - 1;
//         }else{
//             st1 = mid + 1;
//         }
//     }

//     while(st2 <= end2){
//         int mid = st2 + (end2 - st2)/2;
//         if(nums[mid] == target){
//             return mid;
//         }else if(nums[mid] > target){
//             end2 = mid - 1;
//         }else{
//             st2 = mid + 1;
//         }
//     }
   
//     return -1;
// }