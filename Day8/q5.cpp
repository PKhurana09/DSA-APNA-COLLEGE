// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums);

int main(void)
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout << "Index of the num that is single is: " << singleNonDuplicate(nums) << endl;

    return EXIT_SUCCESS;
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int st = 0;
    int end = n - 1;

    while (st < end) {
        int mid = st + (end - st) / 2;

        // force mid to be even
        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) {
            // single element is on the right
            st = mid + 2;
        } else {
            // single element is on the left (or at mid)
            end = mid;
        }
    }

    return nums[st];
    
}























// while (st <= end)
//     {
//         int mid = st + (end - st) / 2;

//         if (mid >= 1 && mid <= n - 2)
//         {
//             if (nums[mid] == nums[mid + 1])
//             {
//                 if (mid % 2 == 0)
//                 {
//                     st = mid + 1;
//                 }
//                 else
//                 {
//                     end = mid - 1;
//                 }
//             }else if(nums[mid] == nums[mid - 1]){
//                 if((mid - 1) % 2 == 0){
//                     st = mid + 1;
//                 }else{
//                     end = mid - 1;
//                 }
//             }else if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
//                 return nums[mid];
//             }
//         }else if(mid == 0){
//             if(nums[mid + 1] != nums[mid]){
//                 return nums[0];
//             }else{
//                 st = mid + 1;
//             }
//         }else if(mid == n - 1){
//             if(nums[mid - 1] != nums[mid]){
//                 return nums[n - 1];
//             }else{
//                 end = mid - 1;
//             }
//         }
//     }

//     return -1;
