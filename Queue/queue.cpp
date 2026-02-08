// Implementing queue using C++ STL

#include<iostream>
#include<queue>

using namespace std;

int main(void){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
        cout << q.front() <<  " ";
        q.pop();
    }
    cout << endl;

    return EXIT_SUCCESS;
}