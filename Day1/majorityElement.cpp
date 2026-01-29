// Given an array ‘nums’ of size n, return the majority element.
// As we have already discussed above, the majority element is the element that appears more than [n / 2] times. If no such element exists, then return -1.

#include<iostream>
#include<vector>

using namespace std;

int majorityElement(vector<int>& nums);

int main(void){
    vector<int> sample ={3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority Element is: " << majorityElement(sample) << endl;
    return EXIT_SUCCESS;
}

int majorityElement(vector<int>& nums){
    int majElement = nums[0];
    int n = nums.size();
    int count = 1;

    for(int i = 1; i != n; ++i){
        if(nums[i] == majElement){
            ++count;
        }else{
            --count;
            if(count == 0){
                majElement = nums[i];
                count = 1;
            }
        }
    }
    int freq = 0;
    for(int i = 0; i != n; ++i){
        if(nums[i] == majElement){
            ++freq;
        }
    }

    if(freq > n/2){
        return majElement;
    }else{
        return -1;
    }
}

