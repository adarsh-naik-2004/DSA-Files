class Solution {
public:
int ans=0;

    void solve(TreeNode* root,long long sum){
        if(!root){
            return;
        }
        if(sum==root->val){
            ans++;
        }
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            solve(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};