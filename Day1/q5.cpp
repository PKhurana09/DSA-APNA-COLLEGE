// Given a non-empty array of integer nums, every element appears twice except for one. Find that single one.You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example : The Mystery of the Extra Guest
// Rahul’s birthday party had a special rule—every friend came with their brother, both having the same name. As guests arrived, Rahul wrote down each name and crossed it off when the brother arrived. In the end, one name remained—the guest without a brother! For example, in [4,1,2,1,2], after canceling pairs, 4 was alone. This simple trick helped Rahul find the extra guest easily!


#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums);

int main(void){
    vector<int> retVal = {4,1,2,1,2};

    cout << "Single Number is: " << singleNumber(retVal);
    
    return EXIT_SUCCESS;
}

int singleNumber(vector<int>& nums){
    int retVal = 0;
    for(int num : nums){
        retVal = retVal^num;
    }
    return retVal;
}