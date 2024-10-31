class Solution {
public:
    bool isValid(string s) {
        stack<char> st;int count=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='a'){
                st.push(ch);
            }
            if(!st.empty() && st.top()=='a' && ch=='b'){
                st.push(ch);
            }
            if(!st.empty() && st.top()=='b' && ch=='c'){
                st.pop();
                st.pop();
                count+=3;
            }
        }
        return count==s.length()?true:false;
    }
};