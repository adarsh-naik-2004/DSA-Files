int recursion(int n) {
    if(n<=1){
        return n;
    }
    return recursion(n-1) + recursion(n-2);
}


//memoization
int topdown(int n, vector<int>& dp){ // vector<int> dp(n+1, -1);  --> n+1 because 0 to n,,  -1 is used for initialization
    if(n<=1){
        return n;
    }
    if(dp[n]!= -1){
        return dp[n];
    }

    dp[n] = topdown(n-1, dp) + topdown(n-2, dp);
    return dp[n];
}

//tabulation
int bottomup(int n){
    vector<int> dp(n+1, -1);

    dp[0] = 0;
    if(n>0){
        dp[1] = 1;
    }
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}