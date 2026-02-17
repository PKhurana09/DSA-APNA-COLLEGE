// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s);

int main(void){
    string s = "(){}[]";
    bool retVal = isValid(s);

    if(retVal){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return EXIT_SUCCESS;
}

bool isValid(string s){
    stack<char> st;

    for(char c: s){
        // if opening bracket then push
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            // check matching pairs
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();    
}
