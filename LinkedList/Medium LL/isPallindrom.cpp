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
    //O(2N) S.C (O(n))
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        string arr;
        while(temp!=nullptr){
            arr += temp->val;
            temp = temp ->next;
        }
        int low = 0;
        int high = arr.size()-1;
        while(low<high && low<arr.size() && high>=0){
            if(arr[low]!=arr[high]) return false;
            low++;
            high--;
        }
    
        return true;
    }

    //Optimal O(2N) O(1)
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next ==nullptr) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* newHead;
        while(fast ->next !=nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        newHead = reverseList(slow->next);
        
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=nullptr){
            if(second->val != first->val){
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};