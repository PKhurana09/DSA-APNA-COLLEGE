// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.


//  Definition for singly-linked list.
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head);

int main(void){
    // Create nodes
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    // Link normally
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;   // no cycle

    // Solution sol;

    // Test 1: no cycle
    // cout << hasCycle(n1) << endl;  // expect 0 (false)

    // Create a cycle: tail -> n2
    // n4->next = n2;

    // Test 2: with cycle
    if(hasCycle(n1)){
        cout << "TRUE" << endl;
    }else{
        cout << "false" << endl;
    }
    // cout << hasCycle(n1) << endl;  // expect 1 (true)
    return EXIT_SUCCESS;
}


bool hasCycle(ListNode* head) {
    ListNode* slowPointer = head;
    ListNode* fastPointer = head;

    while(fastPointer != nullptr && fastPointer->next != nullptr){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if(slowPointer == fastPointer){
            return true;
        }
    }
    return false;
}
