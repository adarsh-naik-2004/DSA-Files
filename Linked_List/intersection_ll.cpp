/*
extra length ko hatao ,, start from same length in both ll
*/
class Solution {
public:
int findlength(ListNode* &head){
    ListNode* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=findlength(headA);
        int len2=findlength(headB);
        if(len1>len2){
            int how=len1-len2;
            ListNode* temp1=headA;
            while(how--){
                temp1=temp1->next;
            }
            ListNode* temp2=headB;
            while(temp1!=NULL){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        else{
            int how=len2-len1;
            ListNode* temp2=headB;
            while(how--){
                temp2=temp2->next;
            }
            ListNode* temp1=headA;
            while(temp1!=NULL){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return NULL;
    }
};