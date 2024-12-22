/*
heavy data structure used here 
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q; // Node,{row,col}
        q.push({root,{0,0}});

        map<int,map<int,multiset<int>>> mp; // col-> row:values (multiset takes care of duplicates also)

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* curr=temp.first;
            auto coordinate=temp.second;
            int row=coordinate.first;
            int col=coordinate.second;

            mp[col][row].insert(curr->val);

            if(curr->left){
                q.push({curr->left,{row+1,col-1}});
            }
            if(curr->right){
                q.push({curr->right,{row+1,col+1}});
            }
        }

        for(auto i:mp){
            auto colvalues=i.second;
            vector<int> level;
            for(auto j: colvalues){
                auto valuesset=j.second;
                
                for(auto k:valuesset){
                    level.push_back(k);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};