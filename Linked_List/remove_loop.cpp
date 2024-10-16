Node* removeloop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(fats!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            slow=head;
            break;
        }
    }
    Node* prev=fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;
    
    return head;
}