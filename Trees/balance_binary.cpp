// 1st approach 2 recurison wala O(N2)
class Solution {
public:

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(isBalanced(root->right) && isBalanced(root->left) && abs(left-right)<=1){
            return true;
        }
        return false;
    }
};

// 2nd approach with pair removing height call and in O(N)

class Solution {
public:

    pair<bool,int> fast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int>left=fast(root->left);
        pair<bool,int>right=fast(root->right);

        int leftheight=left.second;
        int rightheight=right.second;

        pair<bool,int> ans;
        if(left.first && right.first && abs(leftheight-rightheight)<=1){
            ans.first=true;
            ans.second=max(leftheight,rightheight)+1;
        }
        else{
            ans.first=false;
            ans.second=max(leftheight,rightheight)+1;
        }
        
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return fast(root).first;
    }
};
