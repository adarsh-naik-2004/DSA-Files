class Solution {
public:

    // check first for j == t.size() as it means we have found a valid subsequence then check for i == s.size() ---> important

    int recur(string& s, string& t, int i, int j){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        int ans=0; 
        if(s[i]==t[j]){
            ans+=recur(s,t,i+1,j+1);
        }
        ans+=recur(s,t,i+1,j);
        return ans;
    }
    int memo(string& s, string& t, int i, int j, vector<vector<int>>&dp){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0; 
        if(s[i]==t[j]){
            ans+=memo(s,t,i+1,j+1,dp);
        }
        ans+=memo(s,t,i+1,j,dp);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        // return recur(s,t,0,0);
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return memo(s,t,0,0,dp);
    }
};