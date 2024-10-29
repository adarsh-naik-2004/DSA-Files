void insertbottom(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int temp=s.top();
    s.pop();
    insertbottom(s,target);
    s.push(temp);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    insertbottom(s,temp);
}