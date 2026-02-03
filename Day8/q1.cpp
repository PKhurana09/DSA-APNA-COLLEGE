// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

#include<iostream>
#include<vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr);

int main(void){
    vector<int> retVal = {0, 1, 0};

    cout << "Index of mountain element in the array is: " << peakIndexInMountainArray(retVal);

    return EXIT_SUCCESS;
}

int peakIndexInMountainArray(vector<int>& arr){
    int n = arr.size();

    int st = 1;
    int end = n - 2;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(mid != 0 && mid != n -1){
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid;
            }else if(arr[mid] < arr[mid - 1]){
                end = mid - 1;
            }else if(arr[mid] < arr[mid + 1]){
                st = mid + 1;
            }
        }else if(mid == 0){
            if(arr[mid] > arr[mid + 1]){
                return mid;
            }else{
                st = mid + 1;
            }
        }else if(mid == n - 1){
            if(arr[mid] > arr[mid - 1]){
                return mid;
            }else{
                end = mid - 1;
            }
        }
        
    }
    return -1;
}
