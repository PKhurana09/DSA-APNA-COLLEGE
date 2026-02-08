// Implementing queue from scratch using LinkedList

#include<iostream>
#include<list>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = nullptr;
    }

    void push(int data){ // Need to add new node to the tail of the LL; Also need to complete this with the time complexity of O(1)
        Node* newNode = new Node(data);
        if(empty()){ 
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){

        if(empty()){
            cout << "LinkedList is already empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }

        delete temp;
    }

    int front(){
        if(empty()){
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    bool empty(){
        return head == nullptr;
    }
};

int main(void){
    Queue q;
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