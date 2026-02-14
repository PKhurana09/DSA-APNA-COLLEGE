// Given a string s, return the longest palindromic substring in s.


#include<iostream>
#include<string>

using namespace std;

string longestPalindrome(string s);
bool isPlaindrome(string s);

int main(void){
    string s = "aba";

    bool retVal = isPlaindrome(s);

    if(retVal){
        cout << "True" << endl;
    }else{
        cout << "false" << endl;
    }
    return EXIT_SUCCESS;
}

bool isPlaindrome(string s){
    int n = s.size();

    int left = 0;
    int right = n - 1;

    while(left <= right){
        if(s[left] == s[right]){
            ++left;
            --right;
        }
        else{
            return false;
        }
    }

    return true;
}

// string longestPalindrome(string s){

// }
