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
//Optimal Solution 
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp =  head;
        vector<int> arr;
        if(head == nullptr || head->next==nullptr) return head;
        while(temp!=nullptr && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp){
            arr.push_back(temp->val);
        }
         temp =  head->next;
        while(temp!=nullptr  && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        temp = head;
        for(int i =0;i<arr.size();i++){
            temp->val = arr[i];
            temp = temp->next;
        }
        
        return head;
    }

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

    ListNode* OptimaloddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even!=nullptr && even->next!=nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

};