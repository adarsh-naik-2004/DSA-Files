// // left first then right(preorder-> N L R) ,, and using map instead of searching everytime ,, preorderstart isko by reference lena change ho raha hai
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& inorderindex,int &preorderstart,int inorderstart, int inorderend){
        if(preorderstart>=preorder.size() || inorderstart > inorderend){
            return NULL;
        }
        int element=preorder[preorderstart++];
        TreeNode* root = new TreeNode(element);
        int pos=inorderindex[element];
        root->left=solve(preorder,inorder,inorderindex,preorderstart,inorderstart,pos-1);
        root->right=solve(preorder,inorder,inorderindex,preorderstart,pos+1,inorderend);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderindex;
        for(int i=0;i<inorder.size();i++){
            inorderindex[inorder[i]]=i;
        }
        int inorderend=inorder.size()-1;
        int preorderstart=0;
        return solve(preorder,inorder,inorderindex,preorderstart,0,inorderend);
    }
};
