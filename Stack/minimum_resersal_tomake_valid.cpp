int countRev (string s)
{
    stack<char> st;
    if(s.size()%2!=0){
        return -1;
    }
    else{
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty() || st.top()=='}'){
                    st.push(s[i]);
                }
                else if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
            }
        }
        int count=0;
        while(!st.empty()){
            char a=st.top();
            st.pop();
            char b=st.top();
            st.pop();
            if(a==b){
                count+=1;
            }
            else{
                count+=2;
            }
        }
        return count;
    }
}