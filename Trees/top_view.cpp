/*
node ke agar left side jaoge to -1 ,, right to +1 
*/

void print_top(Node* root){
    if(root==NULL){
        return;
    }
    map<int,int> topnode;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontnode=temp.first;
        int hd=temp.second;

        if(topnode.find(hd)==topnode.end()){
            topnode[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }

    cout<<"Printing Answer"<<endl;

    for(auto i : topnode){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}

/* output  --->  0 -> 10
                -1 -> 20
*/