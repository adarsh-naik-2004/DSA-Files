/*
going left ---> +1 ,,, going right ---> do nothing ,, start with 0 (root pe) || 2 approach hai iske
*/

/*
1st approach ---> using map
*/

void solve(Node* root,int d,map<int,vector<int>>& mp){
    if(!root){
        return;
    }
    mp[d].push_back(root->data);
    solve(root->left,d+1,mp);
    solve(root->right,d,mp);
}


vector<int> diagonal(Node *root)
{
   vector<int> ans;
   
   if(!root){
       return ans;
   }
   map<int,vector<int>> mp;
   int d=0;
   
   solve(root,d,mp);
   
   for(auto i:mp){
       for(auto j:i.second){
           ans.push_back(j);
       }
   }
   return ans;
}

/*
2nd approach ---> using queue
*/

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   
   if(!root){
       return ans;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       
       while(temp){
           ans.push_back(temp->data); // right wale ko print karate jao 
           if(temp->left){
               q.push(temp->left); // left wale ko queue me ---> baad me dekh na hai
           }
           temp=temp->right;
       }
   }
   return ans;
}

