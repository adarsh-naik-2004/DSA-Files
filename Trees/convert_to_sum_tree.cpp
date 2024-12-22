class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int convert(Node*&node){
        if(node==NULL){
            return 0;
        }
        
        int original=node->data;
        
        int left=convert(node->left);
        int right=convert(node->right);

        node->data=left+right;
        
        return original+node->data;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        convert(node);
    }
};

class Solution {
public:
    // Helper function to convert the tree to a new sum tree
    int updateSum(Node *node) {
        if (!node) return 0;  // Base case: if node is NULL, return 0

        // Recursively calculate the sums of left and right subtrees
        int leftSum = updateSum(node->left);
        int rightSum = updateSum(node->right);

        // Update the current node's value by adding leftSum, rightSum, and the original value
        node->data = leftSum + rightSum + node->data;

        // Return the sum of the entire subtree rooted at this node to its parent
        return node->data;
    }

    // Function to transform the tree
    void toSumTree(Node *node) {
        updateSum(node);  // Call the helper function to process the entire tree
    }
};

