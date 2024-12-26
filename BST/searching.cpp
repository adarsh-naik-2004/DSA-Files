Node* searchingBst(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data == target){
        return root;
    }
    if(root->data > target){
        return searchingBst(root->left,target);
    }
    else{
        return searchingBst(root->right,target);
    }
}