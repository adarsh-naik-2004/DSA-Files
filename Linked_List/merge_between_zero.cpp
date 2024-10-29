class Solution {
public:

ListNode* again(ListNode* &root){
    if(root==NULL || root->next==NULL){
        return NULL;
    }
                ListNode* temp=root->next;
                int sum=0;
                while(temp->val!=0){
                    sum+=temp->val;
                    temp=temp->next;
                }
                root->val=sum;
                sum=0;
                root->next=again(temp);
                return root;
}


    ListNode* mergeNodes(ListNode* head) {
        return again(head);
    }
};