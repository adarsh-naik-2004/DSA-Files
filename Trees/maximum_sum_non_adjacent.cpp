class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        if(!root){
            return {0,0}; // khud ka ,, niche ka max
        }
        
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        // if root included --> second me niche ka store ho raha
        int a = root->data+left.second+right.second;

        // if root not included 
        int b=max(left.first,left.second)+max(right.first,right.second);
        
        return {a,b};
    }
    
    int getMaxSum(Node *root) 
    {
        auto ans=solve(root);
        
        return max(ans.first,ans.second);
    }
};