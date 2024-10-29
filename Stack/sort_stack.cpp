/*
first part is ,, insert an element(target) in already sorted stack
*/

void insertsorted(stack<int>&s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    /*
    assumming small element at top
    */
    if(s.top()>=target){
        s.push(target);
        return;
    }
    int temp=s.top();
    s.pop();
    insertsorted(s,temp);
    s.push(temp);
}

/*
sort a stack
*/

void sortstack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    sortstack(s);
    insertsorted(s,temp);
}