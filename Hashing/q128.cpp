// 128. Longest Consecutive Sequence


#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums);

int main(void){
// [100, 4, 200, 1, 3, 2]
    return EXIT_SUCCESS;
}

int longestConsecutive(vector<int>& nums){
    if (nums.empty()) return 0;

    unordered_set<int> st(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : st) {

        // Only start counting if it's the beginning of a sequence
        if (st.find(num - 1) == st.end()) {

            int current = num;
            int length = 1;

            while (st.find(current + 1) != st.end()) {
                current++;
                length++;
            }

            maxLen = max(maxLen, length);
        }
    }

    return maxLen;
}
