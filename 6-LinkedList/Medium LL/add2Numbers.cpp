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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        int carry = 0 ;
        while(t1!=nullptr || t2!= nullptr){
            int sum = 0;
            if(carry!=0) sum+=carry;
            if(t1) sum=(sum+t1->val);
            if(t2) sum=(sum+t2->val);

            carry = sum/10;
            sum = sum %10;

            ListNode* node = new ListNode(sum);
            temp->next = node;
            temp = temp->next;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry!=0){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        return newHead->next;
    }
};

// T.C: O(max(N1,N2)), S.C.:O(max(N1,N2))