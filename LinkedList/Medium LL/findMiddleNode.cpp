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
    ListNode* middleNode(ListNode* head) {
        int i = 0;
        ListNode* temp = head;
        while(temp){
            i++;
            temp= temp->next;
        }
        int middle =(i/2)+1;
        temp = head;
        while(middle>1){
            temp = temp->next;
            middle--;
        }
        return temp;
    }
};

