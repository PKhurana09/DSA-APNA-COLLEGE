// Given an integer array nums, rotate the array to the left by one.
// Note: There is no need to return anything, just modify the given array.

#include<iostream>
#include<vector>

using namespace std;

void rotateArrayByOne(vector<int>& nums);

int main(void){
    vector<int> retVal = {1, 2, 3, 4, 5};
    int n = retVal.size();
    cout << "Below is the original array: " << endl;
    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }
    cout << endl;

    rotateArrayByOne(retVal);

    cout << "Below is the array after operation: " << endl;
    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void rotateArrayByOne(vector<int>& nums){
    int n = nums.size();
    int vec = nums[0];

    for(int i = 0; i != n-1; ++i){
        nums[i] = nums[i + 1];
    }

    nums[n-1] = vec;
}