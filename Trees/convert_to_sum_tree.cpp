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