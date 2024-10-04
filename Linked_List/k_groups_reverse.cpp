/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int getlength(ListNode* head){
    ListNode* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}
ListNode* reversek(ListNode* &head,int k){
    if(head==NULL){
        cout<<"LL IS empty";
        return NULL;
    }
    int len=getlength(head);
    if(k>len){
        return head;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;
  
    int count=0;
    ListNode* temp=curr->next;
    while(count<k){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }

    if(curr!=NULL){
        ListNode* recursion=reversek(curr,k);
        head->next=recursion;
    }

    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reversek(head,k);
    }
};