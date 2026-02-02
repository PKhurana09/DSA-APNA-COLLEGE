// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome or false otherwise.

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool isPalindrome(string s);

int main(void){

    string s = "A man, a plan, a canal: Panama";

    bool retVal = isPalindrome(s);

    if(retVal){
        cout << "Yes this is a palindrome";
    }else{
        cout << "No it is not a palindrome";
    }

    return EXIT_SUCCESS;
}

bool isPalindrome(string s){
    if(s.empty()) return true;
    int n = s.length();

    int start = 0;
    int end = n-1;

    while(start <= end){
        if(isalnum(s.at(start)) && isalnum(s.at(end))){
            if(tolower(s.at(start)) != tolower(s.at(end))){
                return false;
            }else{
                ++start;
                --end;
            }
        }else if(!isalnum(s.at(start))){
            ++start;
        }else if(!isalnum(s.at(end))){
            --end;
        }
    }

    return true;
}
