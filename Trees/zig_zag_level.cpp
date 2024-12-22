
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        //initially
        q.push(root);

        bool dir=true;

        while(!q.empty()){
            int size=q.size();
 
            vector<int> level(size);

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                int index=dir ? i : size-i-1;

                level[index] = temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            dir=!dir;

            ans.push_back(level);
        }
        return ans;
    }
};