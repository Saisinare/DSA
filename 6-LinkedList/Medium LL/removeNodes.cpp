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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newList = new ListNode(-1);
        ListNode *newHead = newList;
        ListNode *temp = head;
        while(temp!=nullptr){
            if(temp->val!=val){
                newList->next = temp;
                newList = newList->next;
            }
            temp = temp->next;
        }
        if(newList->next !=nullptr){
            newList->next = nullptr;
        }
        return newHead->next;
    }
};