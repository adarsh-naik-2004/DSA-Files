 /*
 
 */
 
 Node* getmiddle(Node* head){
    if(head==NULL){
        cout<<"LL is Empty";
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fats!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
 }