// 217. Contains Duplicate

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums);

int main(void){
    vector<int> nums = {1, 2, 3, 4};
    bool retVal = containsDuplicate(nums);

    if(retVal){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return EXIT_SUCCESS;
}

bool containsDuplicate(vector<int>& nums){
    int n = nums.size();
    unordered_set<int> hash;

    for(int i = 0; i != n; ++i){
        if(hash.find(nums[i]) != hash.end()){
            return true;
        }
        hash.insert(nums[i]);
    }

    return false;
}
