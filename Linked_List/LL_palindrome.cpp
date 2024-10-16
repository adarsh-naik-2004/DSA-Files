/*
1) normal and reversed comparision ,, tc -> o(n) ,, sc->o(n)

2) tc->o(n) ,, sc->o(1)

approach -> 1)find middle
            2) reverse ll after middle
            3)compare temp1 and temp2

stop when temp2==NULL --> both even and odd case handled
*/

class Solution {
public:
ListNode* reverse(ListNode* &head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* temp=curr->next;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || (head->next==NULL)){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode* head2=reverse(slow->next);
        slow->next=head2;

        ListNode* temp1=head;
        ListNode* temp2=head2;

        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return true;
    }
};

