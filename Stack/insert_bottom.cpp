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