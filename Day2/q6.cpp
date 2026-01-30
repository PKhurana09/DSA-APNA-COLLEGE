// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b ,c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main(void){

    return EXIT_SUCCESS;
}

vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n = nums.size();

    vector<vector<int>> ans;


    sort(nums.begin(), nums.end());

    for(int i = 0; i != n; ++i){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j != n; ++j){
            if(j > 0 && nums[j] == nums[j-1]) continue;
            int start = j + 1;
            int end = n - 1;

            while(start < end){
                long long sum = (long long) nums[i] + nums[j] + nums[start] + nums[end];

                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[start], nums[end]};
                    ans.push_back(temp);
                    while (start < end && nums[start] == nums[start + 1])
                        start++;
                    while (start < end && nums[end] == nums[end - 1])
                        end--;
                    start++;
                    end--;
                }else if(sum > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
    }

    return ans;
}


