class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    int topelement=st.top();
                    if((topelement=='(' && s[i]==')') || (topelement=='[' && s[i]==']') || (topelement=='{' && s[i]=='}')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};