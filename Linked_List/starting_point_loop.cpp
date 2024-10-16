/*
first detect loop ,, take slow to head and start both fast and head again
*/

Node* startingloop(Node* &head){
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
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return fast;
}