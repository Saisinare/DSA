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
};