class Solution{
  public:
  
  void final(Node* root, unordered_map<int,bool> &visited,bool&ans){
      if(!root){
          return;
      }
      visited[root->data]=1;
      if(root->left==0 && root->right==0){
          int a =root->data+1;
          int b =root->data-1 == 0? root->data : root->data-1;
          if(visited.find(a) != visited.end() && visited.find(b) != visited.end()){
              ans=true;
              return;
          }
      }
      final(root->left,visited,ans);
      final(root->right,visited,ans);
  }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool ans = false;
        unordered_map<int,bool> visited;
        final(root,visited,ans);
        return ans;
    }
};