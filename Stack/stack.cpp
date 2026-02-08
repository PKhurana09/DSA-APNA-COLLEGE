// Implmeneting stack using c++ STL

#include<iostream>
#include<stack>

using namespace std;

int main(void){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    while(!st.empty()){
        cout << st.top() <<  " ";
        st.pop();
    }
    cout << endl;

    return EXIT_SUCCESS;
}