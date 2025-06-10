/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//Brute force 
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode* temp = head;
        while(temp){
            if(visited.find(temp->next)!=visited.end()) return temp->next;
            visited.insert(temp);
            temp = temp->next;
        }
        return nullptr;
    }
//Better using tortuis and heir method 
ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow ->next;
            fast = fast ->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
//optimal approach 
ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow ->next;
            fast = fast ->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

};