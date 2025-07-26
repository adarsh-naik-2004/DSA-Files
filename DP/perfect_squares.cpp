class Solution {
public:

    int recur(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        int start=1;
        int mini = INT_MAX;
        while(start*start<=n){
            int ok = 1+recur(n-(start*start));
            mini = min(mini,ok);
            start++;
        }
        return mini;
    }

    int memo(int n, vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int start=1;
        int mini = INT_MAX;
        while(start*start<=n){
            int ok = 1+memo(n-(start*start), dp);
            mini = min(mini,ok);
            start++;
        }
        dp[n]=mini;
        return dp[n];
    }

    int numSquares(int n) {
        // return recur(n)-1;
        vector<int>dp(n+1,-1);
        return memo(n,dp)-1;
    }
};