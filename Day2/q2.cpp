// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the i th line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height);

int main(void){
    vector<int> height = {6, 2, 5, 4, 5, 1};
    cout << "The maximum area will be: " << maxArea(height);
    return EXIT_SUCCESS;
}

int maxArea(vector<int>& height){
    int n = height.size();
    int maxArea = 0;
    int start = 0;
    int end = n - 1;

    while(start != end){
        int area = (end - start) * min(height[start], height[end]);
        maxArea = max(area, maxArea);
        if(height[start] <= height[end]){
            start++;
        }else{
            end--;
        }
    }
    return maxArea;
}
