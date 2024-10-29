void printmiddle(stack<int> &s,int &totalsize){
    if(s.size==0){
        cout<<"No element in stack";
    }
    if(s.size()==(totalsize/2)+1){
        cout<<"Middle element is "<<s.top();
    }
    int temp=s.top();
    s.pop();
    printmiddle(s,totalsize);
    s.push(temp);
}