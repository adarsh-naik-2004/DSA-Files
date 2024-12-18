/*

*/

void printleft(Node* root,vector<int>& ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    printleft(root->left,ans,level+1);
    printleft(root->right,ans,level+1);
}

int main(){
    Node* root=buildtree();
    vector<int> ans;
    int level=0;

    printleft(root,ans,level);

    for(auto i : ans){
        cout<< i <<  " ";
    }
}