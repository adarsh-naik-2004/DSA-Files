void removesorted(Node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && (curr->data==curr->next->data)){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}