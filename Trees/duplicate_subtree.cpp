class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;

    string solve(TreeNode* root){
        if(!root){
            return "N";
        }
        string curr = to_string(root->val);
        string left=solve(root->left);
        string right=solve(root->right);

        string ok=curr+","+left+","+right; // preorder

        if(mp.find(ok)!=mp.end()){
            if(mp[ok]==1){
                ans.push_back(root);
            }
            mp[ok]++;
        }
        else{
            mp[ok]=1;
        }
        return ok;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};