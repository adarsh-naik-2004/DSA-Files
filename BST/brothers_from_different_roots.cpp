/*
using stack
*/

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans=0;
        stack<Node*>a1,a2;
        Node* a=root1;
        Node* b=root2;
        while(true){
            while(a){
                a1.push(a);
                a=a->left;
            }
            while(b){
                a2.push(b);
                b=b->right;
            }
            if(a1.empty() || a2.empty()){
                break;
            }
            auto atop=a1.top();
            auto btop=a2.top();
            
            int sum = atop->data + btop->data;
            
            if(sum == x){
                ans++;
                a1.pop();
                a2.pop();
                a=atop->right;
                b=btop->left;
            }
            else if(sum<x){
                a1.pop();
                a=atop->right;
            }
            else{
                a2.pop();
                b=btop->left;
            }
        }
        return ans;
    }
};

