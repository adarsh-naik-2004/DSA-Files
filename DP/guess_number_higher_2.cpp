class Solution {
public:
int memo(int s,int end,vector<vector<int>>&dp){
 if(s>=end){
    return 0;
 }
 if(dp[s][end]!=-1){
    return dp[s][end];
 }
    int ans=INT_MAX;
    for(int i=s;i<=end;i++){
        ans=min(ans,max(i+memo(s,i-1,dp),i+memo(i+1,end,dp)));
    }
    dp[s][end]=ans;
    return dp[s][end];
}

    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=memo(1,n,dp);
        return ans;
    }
};