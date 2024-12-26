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
    bool findTarget(TreeNode* root, int k) {
        inordertraversal(root);

        int s = 0;
        int e = ans.size() - 1;

        while(s < e) {
            int sum = ans[s] + ans[e];

            if(sum == k ){
                return true;
            }
            if(sum > k){
                e--;
            }
            else{
                s++;
            }
        }

    return false;

    }
};