// Print nums from 1 to N using recurssion

#include<iostream>

using namespace std;

void printNums(int n);

int main(void){
    printNums(6);
    return EXIT_SUCCESS;
}

void printNums(int n){ // recursive function

    if(n == 1){
        cout << "1\n";
        return;
    }

    cout << n << " ";
    printNums(n - 1);

}