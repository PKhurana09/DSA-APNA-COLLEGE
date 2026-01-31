// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);

int main(void){

    return EXIT_SUCCESS;
}

vector<vector<int>> merge(vector<vector<int>>& intervals){
    if(intervals.empty()) return {};

    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for(int i = 1; i != n; ++i){
        if(intervals[i][0] <= ans.back()[1]){
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
