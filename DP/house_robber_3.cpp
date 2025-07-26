/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int memo(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(!root){
            return 0;
        }
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        int include=0;
        include+=root->val;
        if(root->left){
            include+=memo(root->left->left,dp) + memo(root->left->right,dp); 
        }
        if(root->right){
            include+=memo(root->right->left,dp) + memo(root->right->right,dp);
        }
        int exclude = memo(root->left,dp) + memo(root->right,dp);

        dp[root] = max(include,exclude);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return memo(root,dp);
    }
};