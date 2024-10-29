class Solution {
public:
int length(ListNode* &root){
    int count=0;
    ListNode* temp=root;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        int total=length(head);
        k=k%total;
        int ok=total-k-1;
        if(k==total){
            return head;
        }
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        while(ok--){
            head=head->next;
        }
        ListNode* ans=head->next;
        head->next=NULL;
        return ans;
    }
};