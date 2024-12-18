/*
Return First Common Ancestor
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left==NULL && right!=NULL){
            return right;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else{
            return NULL;
        }
    }
};