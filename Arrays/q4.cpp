// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main(void){
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {2, 3, 4, 6};

    cout << "The median of two given arrays is: " << findMedianSortedArrays(nums1, nums2); 
    return EXIT_SUCCESS;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<int> retVal;
    double median;

    int i = 0; 
    int j = 0;

    while(i < n && j < m){
        if(nums1[i] <= nums2[j]){
            retVal.push_back(nums1[i]);
            ++i;
        }else{
            retVal.push_back(nums2[j]);
            ++j;
        }
    }

    while(i < n){
        retVal.push_back(nums1[i]);
        ++i;
    }

    while(j < m){
        retVal.push_back(nums2[j]);
        ++j;
    }

    int ans = retVal.size();

    if(ans % 2 == 0){
        median = (retVal[ans/2] + retVal[ans/2 - 1])/2.0;
    }else{
        median =  retVal[ans/2];
    }

    return median;
}