class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();

                if(tokens[i]=="+"){
                    ans=y+x;
                    st.push(ans);
                }
                if(tokens[i]=="*"){
                    ans=y*x;
                    st.push(ans);
                }
                if(tokens[i]=="/"){
                    ans=y/x;
                    st.push(ans);
                }
                if(tokens[i]=="-"){
                    ans=y-x;
                    st.push(ans);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};