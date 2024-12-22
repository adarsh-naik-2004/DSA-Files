/*
jiska height jyada hai uska sum lena hai ---> longest bloodline
*/

class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(!root){
            return {0,0}; // height , sum
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        int sum=root->data;
        
        if(left.first==right.first){
            sum+=left.second > right.second ? left.second : right.second;
        }
        else if(left.first>right.first){
            sum+=left.second;
        }
        else{
            sum+=right.second;
        }
        return {max(left.first,right.first) + 1 , sum};
    }

    int sumOfLongRootToLeafPath(Node *root) {
        auto ans=solve(root);
        return ans.second;
    }
};