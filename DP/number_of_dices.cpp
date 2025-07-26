class Solution {
public:
    const int MOD = 1e9+7;

    int memo(int n, int k, int target, vector<vector<int>>& dp){
        if(n==0 && target==0){
            return 1;
        }
        if((n!=0 && target==0) || (n==0 && target!=0)){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ways = 0;
        for(int i=1;i<=k;i++){
            if(i <= target){
                ways = (ways + memo(n-1,k,target-i,dp)) % MOD;
            }
        }
        dp[n][target]=ways;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return memo(n,k,target,dp);
    }
};