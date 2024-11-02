/*
method 1 ---> check every row and all column except that row has to be one 

method 2 ---> TC ---> O(N) using stack
*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            int a =st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(mat[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int maybe=st.top();
        st.pop();
        
        for(int i=0;i<n;i++){
            if(mat[maybe][i]!=0){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][maybe]!=1 && i!=maybe){
                return -1;
            }
        }
        return maybe;
    }
};
