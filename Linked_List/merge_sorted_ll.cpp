/*
naya list nhi banana ,, simple banake aage badho ,, no delete and all
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode* temp=&ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            } 
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        
        if(list1!=NULL){
            temp->next=list1;
        } 
        else{
            temp->next=list2;
        }

        return ans.next;
    }
};