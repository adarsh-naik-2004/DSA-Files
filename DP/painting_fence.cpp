class Solution {
  public:
  
  
    int memo(int n, int k, vector<int>& dp){
        if(n==1){
            return k;
        }
        if(n==2){
            return k*k;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] =  (memo(n-2,k,dp) + memo(n-1,k,dp))*(k-1);
        
        return dp[n];
    }
  
    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1, -1);
        return memo(n,k,dp);
    }
};