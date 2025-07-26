class Solution {
public:

    int longest(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if(i>=s.size() || j>=t.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s[i]==t[j]){
            ans=1+longest(s,t,i+1,j+1,dp);
        }
        else{
            ans=max(ans,max(longest(s,t,i+1,j,dp), longest(s,t,i,j+1,dp)));
        }
        return dp[i][j]=ans;
    }

    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return s.size()-longest(s,t,0,0,dp);
    }
};