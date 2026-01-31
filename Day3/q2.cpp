// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation

#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

int main(void){
    vector<int> retVal = {1, 2, 3, 4};
    int n = retVal.size();

    cout << "Array before operations is below: " << endl; 
    for(int i = 0; i != n; ++i){
        cout << retVal[i] << " ";
    }

    cout << endl;
    vector<int> ans =  productExceptSelf(retVal);

    cout << "Array after operations is below: " << endl; 
    for(int i = 0; i != n; ++i){
        cout << ans[i] << " ";
    }

    cout << endl;


    return EXIT_SUCCESS;
}

// Space complexity is O(1)
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();

    vector<int> ans(n, 1);

    // Setting up prefix in ans
    for(int i = 1; i != n; ++i){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    // Setting up suffix in ans
    for(int i = n - 2; i >= 0; --i){
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}


// In this particular case time complexity is O(n) and space complexity is O(n) as well but we need to find better approach where space complexity is constant O(1)
// vector<int> productExceptSelf(vector<int>& nums){
//     int n = nums.size();
//     vector<int> prefix(n, 1);
//     vector<int> suffix(n, 1);
//     vector<int> ans(n, 1);

//     prefix[0] = 1;
//     for(int i = 1; i != n; ++i){
//         prefix[i] = prefix[i - 1] * nums[i - 1]; 
//     }

//     suffix[n-1] = 1;
//     for(int i = n-2; i >= 0; --i){
//         suffix[i] = suffix[i + 1] * nums[i + 1]; 
//     }

//     for(int i = 0; i != n; ++i){
//         ans[i] = prefix[i] * suffix[i];
//     }
//     return ans;
// }
