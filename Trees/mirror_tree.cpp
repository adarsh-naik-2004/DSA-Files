/*
same as same tree ,, bs right ka left and left ka right 
*/

class Solution {
public:
    bool ismirror(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(p && q){
            if((p->val==q->val) && (ismirror(p->left,q->right)) && (ismirror(p->right,q->left))){
                return true;
            }
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
};