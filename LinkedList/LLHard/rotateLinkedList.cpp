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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 1 ;
        ListNode* temp = head;
        if(head==nullptr || head->next == nullptr) return head;
        while(temp->next!=nullptr){
            len++;
            temp = temp->next;
        }

        k = k%len;
        if(k==0) return head;
        temp = head;
        for(int i =0;i<len-k-1;i++){
            temp=temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        temp = newHead;
        while(temp->next !=nullptr){
            temp = temp->next;
        }
        temp ->next = head;
        return newHead;
    }
};