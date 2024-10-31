class Solution {
public:
vector<int> nextgreater(vector<int> &input){
  stack<int> s;
  s.push(INT_MAX);
  
  vector<int> ans(input.size());

  for(int i=input.size()-1;i>=0;i--){
          int curr=input[i];
          while(s.top() <= curr){
            s.pop();
          }
        ans[i]=s.top();
        s.push(curr);
  }
  for(int i=0;i<input.size();i++){
    if(ans[i]==INT_MAX){
        ans[i]=0;
    }
  }
  return ans;
}

vector<int> nextLargerNodes(ListNode* head) {
        vector<int> input;
        ListNode* temp=head;
        while(temp!=NULL){
            input.push_back(temp->val);
            temp=temp->next;
        }
        return nextgreater(input);
    }
};