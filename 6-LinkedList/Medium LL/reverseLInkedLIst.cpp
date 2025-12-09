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
    ListNode* reverseList(ListNode* head) {
        vector<int> result;
        ListNode* temp = head;
        while(temp){
            result.push_back(temp->val);
            temp = temp->next;
        }
        reverse(result.begin(),result.end());
        temp = head;
        for(int i =0;i<result.size();i++){
            temp->val = result[i];
            temp=temp->next;
        }
        return head;
    }

     ListNode* reversing(ListNode* head){
            if(head==nullptr || head->next==nullptr) return head;
            ListNode* newHead = reversing(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
        ListNode* recursiveReverseList(ListNode* head) {
            return reversing(head);    
        }

};