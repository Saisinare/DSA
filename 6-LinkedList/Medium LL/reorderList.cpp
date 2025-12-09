/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Inorder List 
// 1.	find the second half of the linked list 
// 2.	reverse every link in second half 
// 3.	now put pointer on the last element and the first element 
// 4.	for every first half element insert one from last 
// 5.	until end of the first half 
// 6.	put the next of first halfs end at the nullptr 


class Solution {
public:
    ListNode* reversing(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* newHead = reversing(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return reversing(head);    
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        } 

        ListNode* back = reverseList(slow->next);
        slow-> next = nullptr;
        ListNode* front = head;

        while(back!=nullptr && front!=nullptr){
            ListNode* next = front-> next;
            ListNode* nextBack = back->next;
            front-> next = back;
            back-> next = next;
            front = next;
            back = nextBack;
        }

    }
};