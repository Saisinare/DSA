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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0 ;
        ListNode* temp = head;
        if(head==nullptr || head->next == nullptr) return nullptr;
        while(temp!=nullptr){
            temp = temp->next;
            count++;
        }
        int middle = (count%2==0)?ceil((double)count/2):count/2;
        temp = head;
        while(middle!=1){
            temp= temp->next;
            middle--;
        }
        temp ->next = temp->next->next;
        return head;
    }
};