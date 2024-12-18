#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node{
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;     
                this->right = NULL;  
        }
};

int findPosition(int arr[], int n, int element) {
        for(int i=0; i<n; i++) {
                if(arr[i] == element) {
                        return i;
                }
        }
        return -1;
}

Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex, int size, 
int inorderStart, int inorderEnd, unordered_map<int,int> &mapping) {
        //basecase
        if(postIndex < 0 || inorderStart > inorderEnd) {
                return NULL;
        }

        //A
        int element = postorder[postIndex--];
   
        Node* root = new Node(element);

       // int pos = findPosition(inorder,size, element);
        int pos = mapping[element];
        //root->right solve
        root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos+1, inorderEnd, mapping);

        //root->left solve
        root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos-1, mapping);

        return root;


}
