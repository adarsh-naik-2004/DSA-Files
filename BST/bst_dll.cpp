void convertIntoSortedDLL(Node* root, Node* &head) {
	//base case
	if(root == NULL ) {
		return;
	}

	//right subtree into LL
	convertIntoSortedDLL(root->right, head);

	//atach root node
	root->right = head;

	if(head != NULL)
		head -> left = root;

	//update head
	head = root;

	//left subtree linked List
	convertIntoSortedDLL(root->left, head);
}