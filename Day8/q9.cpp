// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.

#include<iostream>
#include<vector>

using namespace std;


int removeElement(vector<int>& nums, int val);


int main(void){
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int n = nums.size();
    cout << "Below is the original array: " << endl;
    for(int i = 0; i != n; ++i){
        cout << nums[i] << " ";
    }

    cout << endl;

    cout << "Number of integers that are non val: " << removeElement(nums, 2) << endl;

    cout << "Below is the array after operation: " << endl;

    for(int i = 0; i != n; ++i){
        cout << nums[i] << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}

int removeElement(vector<int>& nums, int val){
    int n = nums.size();
    int retPointer = 0;
    int counter = 0;
    for(int i = 0; i != n; ++i){
        if(nums[i] != val){
            nums[retPointer] = nums[i];
            ++retPointer;
            ++counter;
        }
    }
    return counter;
}
