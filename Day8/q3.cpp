// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k);

int main(void){

    vector<int> retVal = {1, 2, 3, 4, 5, 6, 7};
    int n = retVal.size();
    cout << "Below is the original array: " << endl;
    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }
    cout << endl;

    rotate(retVal, 3);

    cout << "Below is the array after operation: " << endl;
    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}

void rotate(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;

    int st = 0;
    int end = n - 1;

    while(st <= end){
        int temp = nums[st];
        nums[st] = nums[end];
        nums[end] = temp;
        st++;
        end--;
    }

    st = 0;
    end = k - 1;

    while(st <= end){
        int temp = nums[st];
        nums[st] = nums[end];
        nums[end] = temp;
        st++;
        end--;   
    }

    st = k;
    end = n - 1;

    while(st <= end){
        int temp = nums[st];
        nums[st] = nums[end];
        nums[end] = temp;
        st++;
        end--;   
    }
}