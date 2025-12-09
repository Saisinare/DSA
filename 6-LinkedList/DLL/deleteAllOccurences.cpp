Node * deleteAllOccurrences(Node* head, int k) {
        Node* temp = head;
    if(head==nullptr) return nullptr;
    while (temp != nullptr) {
        if (temp->data == k) {
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
        }
        temp = temp->next;
    }
    return head;
}