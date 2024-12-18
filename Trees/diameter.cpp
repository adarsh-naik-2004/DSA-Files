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
};