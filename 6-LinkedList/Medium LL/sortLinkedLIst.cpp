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
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if(list1!=nullptr) temp->next = list1;
        if(list2!=nullptr) temp->next = list2;
        return dummyNode->next;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* middle = findMid(head);
        ListNode* leftNode = head;
        ListNode* rightNode = middle->next;
        middle->next = nullptr;
        leftNode = sortList(leftNode);
        rightNode = sortList(rightNode);
        return merge(leftNode,rightNode);
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(logn)