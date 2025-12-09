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
    ListNode* findEle(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0 ;
        while(count!=k){
            if(temp==nullptr) return nullptr;
            temp = temp->next;
            count++;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head){
            if(head==nullptr || head->next==nullptr) return head;
            ListNode* newHead = reverseList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* pre;
        while(temp!=nullptr){
            ListNode* kth = findEle(temp,k-1);
            if(kth==nullptr){
                pre->next=temp;
                break;
            }
            ListNode* next = kth->next;
            kth->next = nullptr;
            reverseList(temp);
            if(temp==head){
                head = kth;
            }else{
                pre->next = kth; 
            }
            pre = temp;
            temp = next;
        }
        return head;
    }
};

//T.C:- O(2N) S.C:- O(1)