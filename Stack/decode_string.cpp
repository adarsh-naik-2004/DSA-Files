class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> numst; 
        string ans="";

        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i])){
                int num=s[i]-'0';
                if(isdigit(s[i+1]) && isdigit(s[i+2])){
                    num=num*10+(s[i+1]-'0');
                    num=num*10+(s[i+1]-'0');
                    i+=2;
                }
                if(isdigit(s[i+1]) && !isdigit(s[i+2])){
                    num=num*10+(s[i+1]-'0');
                    i+=1;
                }
                numst.push(num);
            } 
            
            else if(s[i]=='['){
                st.push(s[i]);
            } 

            else if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }

                int r;
                if(!numst.empty()){
                    r=numst.top();
                    numst.pop();
                }

                string repeattemp="";
                while(r--){
                    repeattemp+=temp;
                }

                for(char c:repeattemp){
                    st.push(c);
                }
            } 
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};