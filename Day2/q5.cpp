// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main(void){
    vector<int> sol = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(sol);

    int n = ans.size();

    for(int i = 0; i != n; ++i){
        for(int j = 0; j != 3; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i != n; ++i){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int st = i + 1;
        int end = n - 1;
        while(st < end){
            int sum = nums[i] + nums[st] + nums[end];
            if(sum == 0){
                vector<int> temp = {nums[i], nums[st], nums[end]};
                ans.push_back(temp);

                while(st < end && nums[st] == nums[st + 1]) st++;
                while(st < end && nums[end] == nums[end - 1]) end--;
                st++;
                end--;
            }else if(sum < 0){
                ++st;
            }else{
                --end;
            }
        }
    }
    return ans;
}