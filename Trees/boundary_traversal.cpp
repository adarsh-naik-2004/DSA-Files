/*
divide into three parts ,, 1) divide into 3 parts 
                           2) Left Boundary, Right Boundary, Right Boundary

                           And node ka tension nhi lena hai usko alag se print karwado
*/

void printleftboundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";

    if(root->left){
        printleftboundary(root->left);
    }
    else{
        printleftboundary(root->right);
    }
}

void printrightboundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";

    if(root->right){
        printrightboundary(root->right);
    }
    else{
        printrightboundary(root->left);
    }
}

void printleafboundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }

    printleafboundary(root->left);
    printleafboundary(root->right);
}

void boundarytraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    printleftboundary(root->left);

    printleafboundary(root);
    
    printrightboundary(root->right);
}