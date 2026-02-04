// Given an array arr[] and K, where the array represents the boards and each element of the given array represents the length of each board. K numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. The task is to find the minimum time to get this job done by painting all the boards under the constraint that any painter will only paint the continuous sections of boards.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minTime(vector<int>& arr, int k);
bool isValid(vector<int>& arr, int k, int maxTime);

int main(void){
    vector<int> retVal = {10, 5, 20, 15, 25};
    cout << "Minimum time taken is: " << minTime(retVal, 2);

    return EXIT_SUCCESS;
}

bool isValid(vector<int>& arr, int k, int maxTime){
    int n = arr.size();
    int numPainters = 1;
    int time = 0;

    for(int i = 0; i != n; ++i){
        if(arr[i] > maxTime) return false;

        if(time + arr[i] <= maxTime){
            time = time + arr[i];
        }else{
            ++numPainters;
            time = arr[i];
        }
    }

    return (numPainters <= k);
}

int minTime(vector<int>& arr, int k){
    int n = arr.size();
    int maxTime = 0;

    if(k > n) return -1;

    int st = *max_element(arr.begin(), arr.end());
    int end = 0;
    for(int i = 0; i != n; ++i){
        end = end + arr[i];
    }

    while (st <= end){
        int mid = st + (end - st)/2;

        if(isValid(arr, k, mid)){
            maxTime = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return maxTime;
}