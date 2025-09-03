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
    void solve(TreeNode* root, int targetSum , int &total, vector<int> &path, vector<vector<int>> &ans) {
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        total += root->val;

        if(root->left==NULL && root->right==NULL){
            if(total==targetSum) {
                ans.push_back(path);
            }
        }
        else{
            solve(root->left,targetSum,total,path,ans);
            solve(root->right,targetSum,total,path,ans);
        }
        path.pop_back();
        total-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int total=0;
        solve(root,targetSum,total,path,ans);
        return ans;
    }
};
