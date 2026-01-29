// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2, respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(void){

    // Example input
   vector<int> nums1 = {1, 2, 3, 0, 0, 0};
   int m = 3;
   vector<int> nums2 = {2, 5, 6};
   int n = 3;

   // Call the optimized merge function
   merge(nums1, m, nums2, n);


   // Print the merged array
   cout << "Merged array: ";
   for (int num : nums1) {
       cout << num << " ";
   }
   cout << endl;



    return EXIT_SUCCESS;
}

// In this we can not use the seprate array we have to adjust it inside the 1st array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int index = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while(i >= 0 && j >= 0){
        if(nums2[j] >= nums1[i]){
            nums1[index] = nums2[j];
            --index;
            --j;
        }else{
            nums1[index] = nums1[i];
            --index;
            --i;
        }   
    }

    while(j >= 0){
        nums1[index] = nums2[j];
        --index;
        --j;
    }

}


