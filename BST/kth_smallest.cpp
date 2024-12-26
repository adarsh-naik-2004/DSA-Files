/*
1) Inorder store karke
*/
class Solution {
public:
vector<int> ans;
   void inordertraversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        else{
        inordertraversal(root->left);
        int temp=root->val;
        ans.push_back(temp);
        inordertraversal(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inordertraversal(root);
        return ans[k-1];
    }
};

/*
2) Recursively
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        
        //base case
        if(root == NULL) {
            //-1 reflects base condition reached
            return -1;
        }

        //INorder

        //left
        int leftAns = kthSmallest(root->left,k);

        if(leftAns != -1)
            return leftAns;

        //N -> root
        k--;
        if(k == 0)  {
            return root->val;
        }

        //right
        int rightAns = kthSmallest(root->right, k);
        return rightAns;

    }
};