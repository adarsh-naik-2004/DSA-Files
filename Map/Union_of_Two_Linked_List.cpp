class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        map<int,Node*> mp;
        Node* curr=head1;
        
        while(curr){
            mp[curr->data]=curr;
            curr=curr->next;
        }
        
        curr=head2;
        
        while(curr){
            mp[curr->data]=curr;
            curr=curr->next;
        }
        
        Node* temp=NULL;
        
        curr=0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if(temp==NULL){
                temp=it->second;
                curr=temp;
            }
            else{
                curr->next=it->second;
                curr=curr->next;
            }
        }
        curr->next=NULL;
        
        return temp;
        
        
    }
};