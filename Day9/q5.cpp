// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.



// Definition for singly-linked list.

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main(void){
    return EXIT_SUCCESS;        
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode dummy(0);
    ListNode* retVal = &dummy;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val <= list2->val){
            retVal->next = list1;
            list1 = list1->next;
        }else{
            retVal->next = list2;
            list2 = list2->next;
        }
        retVal = retVal->next;
    }

    if(list1 != nullptr){
        retVal->next = list1;
    }else{
        retVal->next = list2;
    }

    return dummy.next;
}
