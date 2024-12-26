/*
inorder store karake dono answer done
*/

int minval(Node* root){
    Node* temp=root;

    if(temp==NULL){
        return -1;
    }

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int maxVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {
		temp = temp ->right;
	}
	return temp -> data;
}