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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* result  = new ListNode(-1);
        ListNode* newHead = result ;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                result->next = l1;
                l1 = l1->next;
            }else{
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        if(l1!=nullptr) result->next = l1;
        else if(l2!=nullptr) result->next = l2;
        return newHead->next;
    }
};