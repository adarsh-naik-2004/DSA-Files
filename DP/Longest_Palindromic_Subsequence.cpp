class Solution {
public:

    // REVERSE ---> HINT

    int recur(string&t, string&s, int i, int j){
        if(i>=t.size() || j>=s.size()){
            return 0;
        }
        int ans=INT_MIN;
        if(t[i]==s[j]){
            ans=1+recur(t,s,i+1,j+1);
        }
        else{
            ans=max(recur(t,s,i,j+1), recur(t,s,i+1,j));
        }
        return ans;

    }

    int memo(string&t, string&s, int i, int j, vector<vector<int>>& dp){
        if(i>=t.size() || j>=s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(t[i]==s[j]){
            ans=1+memo(t,s,i+1,j+1,dp);
        }
        else{
            ans=max(memo(t,s,i,j+1,dp), memo(t,s,i+1,j,dp));
        }
        return dp[i][j]=ans;

    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size(),-1));
        return memo(t,s,0,0,dp);
    }
};