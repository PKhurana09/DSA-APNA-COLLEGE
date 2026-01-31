// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.


#include<iostream>
#include<vector>
#include<set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix);

int main(void){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i != m; ++i){
        for(int j = 0; j != n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

void setZeroes(vector<vector<int>>& matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    vector<pair<int, int>>  ans;

    vector<int> rows(r, 1);
    vector<int> columns(c, 1);

    for(int i = 0; i != r; ++i){
        for(int j = 0; j != c; ++j){
            if(matrix[i][j] == 0){
                rows[i] = 0;
                columns[j] = 0;
            }
        }
    }

    for(int i = 0; i != r; ++i){
        for(int j = 0; j != c; ++j){
            if(rows[i] == 0 || columns[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
}
