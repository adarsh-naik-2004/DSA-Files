class Solution {
public:
vector<int> ans;
   void inordertraversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        else{
            inordertraversal(root->left);
            int temp=root->val;
            ans.push_back(temp);
            inordertraversal(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        inordertraversal(root);
        bool result = true;
        for (int i = 1; i < ans.size(); i++){
        if (ans[i] <= ans[i-1])
        {
            result = false;
            break;
        }
    }
        if(result){
            return true;
        }
        else{
            return false;
        }
    }
};