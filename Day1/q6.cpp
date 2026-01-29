// We are given two variables x and n. Implement pow(x, n), which calculates x raised to the power n (i.e., x^n)

#include<iostream>
#include<vector>

using namespace std;

double myPow(double x, int n);

int main(void){
    cout << "X raise to power n is: " << myPow(2.00, 10);

    return EXIT_SUCCESS;
}

double myPow(double x, int n){
    if(n == 0) return 1.00;
    if(x == 0) return 0.00;
    if(x == 1) return 1.00;
    

    long binFrm = n;
    if(n < 0){
        x = 1/x;
        binFrm = - binFrm;
    }
    double ans = 1;

    while(binFrm > 0){
        if(binFrm % 2 == 1){
            ans *= x;
        }

        x *= x;
        binFrm /= 2;
    }
    return ans;
}

