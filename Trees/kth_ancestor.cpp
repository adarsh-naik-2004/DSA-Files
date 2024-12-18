bool solve(Node *root, int &k, int node,int &ans){
    if(root==NULL){
        return false;
    }
    if(root->data==node){
        return true;
    }
    
    bool left=solve(root->left,k,node,ans);
    bool right=solve(root->right,k,node,ans);
    
    if(left || right){
        k--;
    }
    if(k==0){
        ans=root->data;
        k=-1; // imp to avoid multiple answers as k becomes zero ones than it becomes zero for others also
    }
    
    return left||right;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    solve(root,k,node,ans);
    return ans;
}
