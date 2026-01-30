// Given an array nums with n objects colored red, white, or blue, sort them in place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0 , 1 , and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums);

int main(void){
    vector<int> intArray = {2,0,2,1,1,0};
    int n = intArray.size();

    cout << "Array before modifications is below: " << endl;
    for(int i = 0; i != n; ++i){
        cout << intArray[i] << " ";
    }

    cout << endl;

    sortColors(intArray);

    cout << "Array after modifications is below: " << endl;
    for(int i = 0; i != n; ++i){
        cout << intArray[i] << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}

void sortColors(vector<int>& nums){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int n = nums.size();

    for(int i = 0; i != n; ++i){
        if(nums[i] == 0){
            ++count0;
        }else if(nums[i] == 1){
            ++count1;
        }else{
            ++count2;
        }
    }

    for(int i = 0; i != count0; ++i){
        nums[i] = 0;
    }

    for(int i = count0; i != count0 + count1; ++i){
        nums[i] = 1;
    }

    for(int j = count0 + count1; j != count0 + count1 + count2; ++j){
        nums[j] = 2;
    }
}