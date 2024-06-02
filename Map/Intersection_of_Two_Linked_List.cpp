class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        
        unordered_map<int,int> mp;
        
        Node* curr=head2;
        
        while(curr){
            mp[curr->data]++;
            curr=curr->next;
        }
        
        Node* ans=NULL;
        Node* temp=0;
        curr=head1;
        
        while(curr){
            if(mp.find(curr->data) != mp.end()){
                
                    
                    if(ans==NULL){
                        ans=curr;
                        temp=ans;
                    }
                    else{
                        if(mp[curr->data]>0){
                            temp->next=curr;
                            temp=temp->next;  
                            mp[curr->data]--;
                        }
                    }
            }
            curr=curr->next;
        }
        if(temp){
         temp->next=NULL;   
        }
        return ans;
    }
};
