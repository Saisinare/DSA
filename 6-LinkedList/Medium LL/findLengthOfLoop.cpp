/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    Node *fast =head;
    Node *slow =head;
    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
      slow = slow ->next;
      fast = fast->next->next;
      if(fast == slow){
          slow = slow->next;
          int count = 1;
          while(slow!=fast){
              slow=slow->next;
              count++;
          }
          return count;
      }  
    }
    return 0;

}
