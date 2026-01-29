// You are given a 0-indexed 2D integer matrix of size n*n with values in the range [1, n²]. Each integer appears exactly once except a, which appears twice, and b, which is missing. The task is to find the repeating and missing numbers a and b, respectively.
// Return a 0-indexed integer array ‘ans’ of size 2, where ans[0] is equal to a and ans[1] is equal to b.


#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid);

int main(void){
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};

    vector<int> retVal = findMissingAndRepeatedValues(grid);

    cout << "Repeated value is: " << retVal[0] << " and missing value is: " << retVal[1]; 

    return EXIT_SUCCESS;
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    vector<int> retVal;
    unordered_set<int> mp;
    int n = grid.size();
    int a, b;
    int actualSum = 0; 
    int expectedSum = 0;

    for(int i = 0; i != n; ++i){
        for(int j = 0; j != n; ++j){
            actualSum += grid[i][j];
            if(mp.find(grid[i][j]) != mp.end()){
                a = grid[i][j];
                retVal.push_back(a);
            }
            mp.insert(grid[i][j]);
        }
    }

    expectedSum = (n*n) * ((n*n) + 1)/2;

    b = expectedSum + a - actualSum;
    retVal.push_back(b);

    return retVal;
}
