Node * removeDuplicates(Node *head)
{
    Node *first = head;
    Node *second = head->next;
    if(head==nullptr || head->next == nullptr) return head;
    while(second!=nullptr){
        if(first->data != second->data ){
            first->next = second;
            second->prev = first;
            first = first->next;
        }
        second = second->next;
    } 
    if(first->next !=nullptr) first->next = nullptr;
    return head;
 
}

