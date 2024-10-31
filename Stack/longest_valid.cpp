/*
Length based questions me sirf index pe dhyan do

By default -1 push karke rakho to find lenght

close bracket --> pop karo --> if stack empty then push current index (as we are ignoring the close bracket as invlaid bracket and length will be calculated from that index),, else find lenght = currentindex - s.top()

open bracket --> push current index 

index starts from zero here
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxl=0;

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len=i-st.top();
                    maxl=max(maxl,len);
                }
            }

        }
      return maxl;
    }
    
};