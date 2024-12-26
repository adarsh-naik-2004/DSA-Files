class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
}


void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintoBST(root,data);
        cin>>data;
    }
}

Node insertintoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(root->data > data){
        root->left=insertintoBST(root->left,data);
    }
    else{
        root->right=insertintoBST(root->right,data);
    }
    return root;
}

int main(){
    Node* root=NULL;

    cout<<"Enter the data for Node"<<endl;

    takeinput(root);

    cout<<"printing the tree"<<endl;

    levelordertraversal(root); // same code as tree 

    return 0;
}