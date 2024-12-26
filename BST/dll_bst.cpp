Node* sortedLinkedListIntoBST(Node* &head, int n) {
	//base case
	if(n <= 0 || head == NULL)
		return NULL;

	Node* leftSubtree = sortedLinkedListIntoBST(head, n/2);

	Node* root = head;
	root->left = leftSubtree;

	head = head -> right;
	
	//right part solve karna h 
	root->right = sortedLinkedListIntoBST(head,n-1-n/2);
	return root;
}