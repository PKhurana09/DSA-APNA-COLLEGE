// Given an array stalls[ ] containing distinct integers representing stall locations and an integer k representing the number of aggressive cows, your task is to assign stalls to the cows such that the minimum distance between any two cows is maximized.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int aggressiveCows(vector<int>& stalls, int cows);
bool isValid(vector<int>& stalls, int cows, int minDistance);

int main(void){

    return EXIT_SUCCESS;
}

bool isValid(vector<int>& stalls, int cows, int minDistance){
    int n = stalls.size();
    int cowsPlaced = 1;
    int currentIndex = 1;
    int lastPlacedIndex = 0;

    while(currentIndex < n && cowsPlaced < cows){
        if(stalls[currentIndex] - stalls[lastPlacedIndex] >= minDistance){
            ++cowsPlaced;
            lastPlacedIndex = currentIndex;
        }
        currentIndex++;
    }
    return (cowsPlaced == cows);
}

int aggressiveCows(vector<int>& stalls, int cows){
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int range = stalls[n-1] - stalls[0];

    int maxMinDistance = 1;

    int st = 1; // minimum distance can be 1. Because there has to be 2 cows atleast so therefore minimum distance is 1
    int end = range; // This is the maximum distance between 2 cows. so our distance has to be between st and end

    while(st < end){
        int mid = st + (end - st)/2;
        if(isValid(stalls, cows, mid)){
            maxMinDistance = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return maxMinDistance;
}