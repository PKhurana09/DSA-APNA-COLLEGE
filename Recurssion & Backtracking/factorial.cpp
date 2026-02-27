// calculate n factorial using recursion

#include<iostream>

using namespace std;

int factorial(int n);

int main(void){
    cout << "Factorial of 5 is: " << factorial(5) << endl;
    
    return EXIT_SUCCESS;
}

int factorial(int n){
    if( n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}