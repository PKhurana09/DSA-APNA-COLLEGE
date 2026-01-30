// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(void){

    return EXIT_SUCCESS;
}

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;

    set<vector<int>> retVal;

    for(int i = 0; i != n; ++i){
        for(int j = i + 1; j != n; ++j){
            for(int k = j + 1; k != n; ++k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};

                    sort(temp.begin(), temp.end());
                }
            }
        }
    }
}
