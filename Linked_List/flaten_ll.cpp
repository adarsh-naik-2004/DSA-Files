/*
merge ll type hai but bottom aur next aagaya hai extra
*/

/*
Input:
5 -> 10 -> 19
|     |     |
7     20    22
|     |     |
8     30    50
|
30

Step 1: Flatten reaches the rightmost node (19)
Step 2: Starts merging from right to left
Step 3: First merges 19's list with 10's list
Step 4: Then merges the result with 5's list

Output: Single sorted list using bottom pointers:
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 30 -> 30 -> 50
*/

Node *merge(Node *a, Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node *ans=0;
    if(a->data < b->data){
        ans=a;
        a->bottom=merge(a->bottom,b);
    }
    else{
        ans=b;
        b->bottom=merge(a,b->bottom);
    }
    return ans;
}

class Solution {
  public:
    Node *flatten(Node *root) {
        if(root==NULL){
            return 0;
        }
        Node *merged=merge(root,flatten(root->next));
        return merged;
    }
};