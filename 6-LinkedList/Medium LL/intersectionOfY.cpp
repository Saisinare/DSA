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
    //brute force solution: store in the data sturture like set or hashmap and then check from the second linked list for the common element 
        

    //better solution 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int a=0, b=0;
        while(tempA!=nullptr){
            tempA = tempA->next;
            a++;
        }
        while(tempB!=nullptr){
            tempB = tempB->next;
            b++;
        }
        tempB = headB;
        tempA = headA;

        if(a>b){
            int res = a-b;
            while(res && tempA!=nullptr){
                tempA = tempA->next;
                res--;
            }
        }
        if(b>a){
            int res = b-a;
            while(res && tempB!=nullptr){
                tempB = tempB->next;
                res--;
            }
        }

        while(tempA!=nullptr && tempB!=nullptr){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return nullptr;
    }
    
    //optimal 

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta = headA;
        ListNode *tb = headB;
        if(headA==nullptr || headB == nullptr) return nullptr;
        if(headA==headB) return headA;
        while(ta!=tb){
            ta = (ta==nullptr) ? ta = headB : ta->next; 
            tb = (tb==nullptr) ? tb = headA : tb->next; 
        }
        return ta;
    }
};