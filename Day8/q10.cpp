// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int>& digits);

int main(void){
    vector<int> digits = {1, 2, 3};

    int n = digits.size();

    plusOne(digits);

    cout << "Array after operation is: " << endl;
    for(int i = 0; i != n; ++i){
        cout << digits[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}

vector<int> plusOne(vector<int>& digits){
    int n = digits.size();

    for(int i = n - 1; i >= 0; --i){
        if(digits[i] < 9){
            digits[i] += 1;
            return digits;
        }

        digits[i] = 0;
    }

    // If we reach here all digits were 9
    digits.insert(digits.begin(), 1);
    return digits;
}
