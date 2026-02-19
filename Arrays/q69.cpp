// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.

#include<iostream>
#include<vector>

using namespace std;

int mySqrt(int x);

int main(void){

    cout << "square root of 8 is: " << mySqrt(8);

    return EXIT_SUCCESS;
}

int mySqrt(int x){
    int retVal = -1;
    int st = 0;
    int end = x;

    if (x == 0) return 0;
    
    while( st < end){
        long long mid = st + (end-st)/2;

        if(mid*mid == x){
            return mid;
        }else if(mid*mid > x){
            end = mid - 1;
        }else{
            retVal = mid;
            st = mid + 1;
        }
    }

    return retVal;
}