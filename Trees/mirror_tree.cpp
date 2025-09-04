/*
same as same tree ,, bs right ka left and left ka right 
*/

class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)){
            return false;
        }
        if(solve(p->left,q->right) && solve(p->right,q->left) && p->val==q->val){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};
