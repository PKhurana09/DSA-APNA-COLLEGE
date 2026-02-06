// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.


#include<iostream>

using namespace std;


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* detectCycle(ListNode* head);

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
    ListNode* retVal = detectCycle(n1);

    if(retVal != nullptr){
        cout << retVal->val << endl;
    }else{
        cout << "-1";
    }
    return EXIT_SUCCESS;
}

ListNode* detectCycle(ListNode* head){
    ListNode* slowPointer = head;
    ListNode* fastPointer = head;

    while(fastPointer != nullptr && fastPointer->next != nullptr){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if(slowPointer == fastPointer){
            slowPointer = head;
            while(slowPointer != fastPointer){
                slowPointer = slowPointer->next;
                fastPointer = fastPointer->next;
            }
            return slowPointer;
        }
    }

    return nullptr;
}