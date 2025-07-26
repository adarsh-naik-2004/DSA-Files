class Solution {
public:

    int memo(vector<int>& prices, int i, int buy, vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int maxi=INT_MIN;
        if(buy){
            int profit1=memo(prices,i+1,0,dp) - prices[i];
            int ignore1=memo(prices,i+1,1,dp);
            maxi=max(maxi,max(profit1,ignore1));
        }
        else{
            int profit2=memo(prices,i+2,1,dp) + prices[i];
            int ignore2=memo(prices,i+1,0,dp);
            maxi=max(maxi,max(profit2,ignore2));
        }
        dp[i][buy]=maxi;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return memo(prices,0,1,dp);
    }
};