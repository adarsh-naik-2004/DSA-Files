class Solution {
public:
    int memo(vector<int>& prices, int i, int buy, int limit,vector<vector<vector<int>>>& dp){
        if(i>=prices.size() || limit==0){
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }

        int maxi = INT_MIN;

        if(buy){
            int profit1 = memo(prices,i+1,0,limit,dp) - prices[i];
            int ignore1 = memo(prices,i+1,1,limit,dp);
            maxi = max(maxi,max(profit1,ignore1));
        }
        else{
            int profit2 = memo(prices,i+1,1,limit-1,dp) + prices[i];
            int ignore2 = memo(prices,i+1,0,limit,dp);
            maxi = max(maxi,max(profit2,ignore2));
        }
        dp[i][buy][limit]=maxi;
        return dp[i][buy][limit];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memo(prices,0,1,k,dp);
    }
};