// Implementing circular queue using arrays

#include<iostream>

using namespace std;

class CircularQueue{
    int* arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    void push(int data){
        if(currSize == cap){
            cout << "CQ is full\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout << "CQ is empty\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front(){
        if(empty()){
            cout << "CQ is empty\n";
            return -1;
        }

        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }
};