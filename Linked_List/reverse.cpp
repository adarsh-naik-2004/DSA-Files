/*
curr --> head ,,, prev ---> NULL ,,, in int main()
*/

Node* reverse(Node* prev,Node* curr){
    if(curr==NULL){
        return prev;
    }
    Node* temp=crr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    return reverse(prev,curr);
}