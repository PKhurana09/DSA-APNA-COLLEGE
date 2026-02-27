// Sum of n numbers using recursion

#include<iostream>

using namespace std;

int sum(int num);

int main(void){
    
    cout << "Sum of first 5 natural numbers is: " << sum(5) << endl;

    return EXIT_SUCCESS;
}

int sum(int num){
    if( num == 1){
        return 1;
    }

    return num + sum( num - 1);
}