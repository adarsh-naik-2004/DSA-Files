class Solution {
public:
void reversest(stack<string> st,string &ans){
    if(st.empty()){
        return;
    }
    string ok=st.top();
    st.pop();
    reversest(st,ans);
    ans+=ok;
}
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end=i+1;
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            string words=path.substr(start,end-start);
            i=end;

            if(words=="/" || words=="/."){
                continue;
            }
            if(words!="/.."){
                st.push(words);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string ans="";
        if(st.empty()){
            ans="/";
        }
        else{
            reversest(st,ans);
        }
        return ans;
    }
};