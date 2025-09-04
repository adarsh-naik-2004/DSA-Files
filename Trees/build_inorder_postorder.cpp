// right first then left ,, and using map instead of searching everytime ,, postorderstart isko by reference lena change ho raha hai

class Solution {
public:

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&inorderindex,int &postorderstart,int inorderstart, int inorderend){
        if(postorderstart<0 || inorderstart > inorderend){
            return NULL;
        }
        int element=postorder[postorderstart--];
            
        TreeNode* root=new TreeNode(element);
            
        int pos=inorderindex[element];
            
        root->right=solve(inorder,postorder,inorderindex,postorderstart,pos+1,inorderend);
        root->left=solve(inorder,postorder,inorderindex,postorderstart,inorderstart,pos-1);
            
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderindex;
        for(int i=0;i<inorder.size();i++){
            inorderindex[inorder[i]]=i;
        }
        int postorderstart=postorder.size()-1;
        int inorderend=inorder.size()-1;
        return solve(inorder,postorder,inorderindex,postorderstart,0,inorderend);
    }
};
