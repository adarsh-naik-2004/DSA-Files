class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> posi;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        int mini=INT_MAX;int maxi=INT_MIN;int count=1;
        ListNode* temp=head;
        while(temp->next->next!=NULL){
            int a1=temp->val;int a2=temp->next->val;int a3=temp->next->next->val;
            if((a2>a1 && a2>a3) || (a2<a1 && a2<a3)){
                int ok=count+1;
                posi.push_back(ok);
            }
            temp=temp->next;
            count++;
        }
        int n=posi.size();
        if(n<2){
            return {-1,-1};
        }
        for(int i=1;i<n;i++){
            mini=min(mini,posi[i]-posi[i-1]);
        }
        maxi=posi[n-1]-posi[0];
        posi.clear();
        posi.push_back(mini);
        posi.push_back(maxi);
        return posi;
    }
};