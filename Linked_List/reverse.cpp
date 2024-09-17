/*
curr --> head ,,, prev ---> NULL ,,, in int main()
*/

Node* reverse(Node* prev,Node* curr){
    if(curr==NULL){
        return prev;
    }
    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    return reverse(prev,curr);
}

/*
 iteratively ---> simple loop
*/
ListNode* reverseok(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;

    while(curr!=NULL){
    ListNode* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    }  
    return prev;
}

