// PairSum Problem. In This Problem we are given a sorted array and a target value. We have to find the index value of 2 elements whose sum make the target value

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pairSum(vector<int> &nums, int target);

int main(void)
{
    vector<int> name = {2, 5, 6, 7, 8, 11, 15};

    cout << "The two indexes that make the sum to the target are: " << endl;
    
    vector<int> retVal = pairSum(name, 10);

    for(int i = 0; i != 2; ++i){
        cout << retVal[i] << " ";
    }

    return EXIT_SUCCESS;
}


// Two Pointers approach this is the best approach as it will be using Time Complexity of O(N) and space complexity of O(1)
vector<int> pairSum(vector<int> &nums, int target){
    int start = 0, end = nums.size() - 1;

    while(start < end){
        int sum = nums[start] + nums[end];

        if(sum == target){
            return {start, end};
        }else if(sum < target){
            start++;
        }else{
            end--;
        }
    }

    return {};
}






// Below is the approach for Optimal hashing Approach. In this case time Complexity O(N) and space complexity is O(1)
// vector<int> pairSum(vector<int> &nums, int target){
//     unordered_map<int, int> mp;
//     int n = nums.size();

//     for(int i = 0; i != n; ++i){
//         int need = target - nums[i];

//         if(mp.find(need) != mp.end()){
//             return {mp[need], i};
//         }

//         mp[nums[i]] = i;
//     }

//     return {};
// }



// In the below approach there is time complexity of O(n^2) and space complexity of O(n). NOT OPTIMAL APPROACH
// vector<int> pairSum(vector<int> &nums, int target)
// {
//     unordered_map<int, int> mp;
//     vector<int> retVal;
//     int n = nums.size();
//     bool out = true;
//     int i = 0;

//     while (out && i != n)
//     {
//         if (!mp.empty())
//         {
//             for (auto it : mp)
//             {
//                 if (it.first + nums[i] == target)
//                 {
//                     out = false;
//                     retVal.push_back(it.second);
//                     retVal.push_back(i);
//                     break;
//                 }
//             }
//         }
//         mp[nums[i]] = i;
//         ++i;
//     }

//     return retVal;
// }