// 1st Approach --> Inorder sorted hai ki nahi check karlo

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
            if (ans[i] <= ans[i-1]){
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

// 2nd approach --> ek range ke ander hona chahiye 

class Solution {
public:

    bool solve(TreeNode* root,long long min,long long max){
        if(root==NULL){
            return true;
        }
        if(root->val > min && root->val < max){
            bool left=solve(root->left,min,root->val);
            bool right=solve(root->right,root->val,max);

            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
