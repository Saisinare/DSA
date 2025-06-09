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
    //** brute force **
    bool bruteHasCycle(ListNode *head) {
        
        set<ListNode*> visited;
        ListNode *temp = head;
        while(temp!=nullptr ){
            if(visited.find(temp)!=visited.end()) return true; 
            visited.insert(temp);
            temp=temp->next;
        }
        return false;
    }
    bool OptimalhasCycle(ListNode *head) {
        
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};