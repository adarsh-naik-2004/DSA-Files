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
    int rangeSumBST(TreeNode* root, int low, int high) {
        inordertraversal(root);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                sum+=ans[i];
            }
        }
        return sum;
    }
};