class Solution {
public:
void inorder(TreeNode* root,vector<int>& in){
    if(!root){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
TreeNode* buildtree(vector<int>& in,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(in[mid]);
    root->left=buildtree(in,start,mid-1);
    root->right=buildtree(in,mid+1,end);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return buildtree(in,0,in.size()-1);
    }
};