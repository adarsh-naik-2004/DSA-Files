class Solution {
  public:
  
    int recur(int W, vector<int> &val, vector<int> &wt, int n) {
        if(n<0){
            return 0;
        }
        if(n==0){
            if(wt[0] <= W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        int include = 0;
        if(wt[n] <= W){
            include = recur(W-wt[n],val,wt,n-1) + val[n];
        }
        int exclude = recur(W,val,wt,n-1);
        
        return max(include,exclude);
    }
    
    int memo(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>>& dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            if(wt[0] <= W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        int include = 0;
        if(wt[n] <= W){
            include = memo(W-wt[n],val,wt,n-1,dp) + val[n];
        }
        int exclude = memo(W,val,wt,n-1,dp);
        
        dp[n][W] = max(include,exclude);
        
        return dp[n][W];
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(W+1,-1));
        
        // return recur(W,val,wt,n-1);
        
        return memo(W,val,wt,n-1,dp);
        
    }
};