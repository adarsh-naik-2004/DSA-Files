class Solution {
public:
// 1st approach 2 recursion O(N2)
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL){
            return 0;
        }

        // This path may or may not pass through the root
        int leftnode=diameterOfBinaryTree(root->left);
        int rightnode=diameterOfBinaryTree(root->right);

        // Root se MAX Length
        int left=height(root->left);
        int right=height(root->right);
        int rootmax=left+right;

        int ans3=max(rootmax,max(leftnode,rightnode));

        return ans3;
    }

// 2nd Approach --> O(N) using pairs first -> diameter , second -> height
class Solution {
public:

    pair<int,int> diameterfast(TreeNode* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterfast(root->left);
        pair<int,int> right=diameterfast(root->right);

        int leftsubtree=left.first;
        int rightsubtree=right.first;
        int throughthatnode=left.second+right.second;

        pair<int,int> ans;
        ans.first=max(leftsubtree,max(rightsubtree,throughthatnode));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterfast(root).first;
    }
};
};
