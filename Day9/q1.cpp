// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.


// Definition for singly-linked list.
struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int counter = 0;
//         ListNode* temp = head;
//         while(temp != nullptr){
//             ++counter;
//             temp = temp->next;
//         }

//         int target = counter/2;

//         ListNode* node = head;
//         while(target--){
//             node = node->next;
//         }

//         return node;
//     }
// };


 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer != nullptr && fastPointer->next != nullptr){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};