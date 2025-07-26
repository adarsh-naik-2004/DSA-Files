class Solution {
public:

    int recur(vector<int>& piles, int curr, int m, int alice){
        if(curr>=piles.size()){
            return 0;
        }
        int maxi = alice ? INT_MIN : INT_MAX;
        int total=0;
        for(int i=1;i<=2*m;i++){
            if(curr+i-1 >= piles.size()){
                break;
            }
            total+=piles[curr+i-1];
            if(alice){
                maxi=max(maxi, total+recur(piles,curr+i,max(i,m),!alice));
            }
            else{
                maxi=min(maxi, recur(piles,curr+i,max(i,m),!alice));
            }
        }
        return maxi;
    }

    int memo(vector<int>& piles, int curr, int m, int alice, vector<vector<vector<int>>>& dp){
        if(curr>=piles.size()){
            return 0;
        }
        if(dp[curr][m][alice]!=-1){
            return dp[curr][m][alice];
        }
        int maxi = alice ? INT_MIN : INT_MAX;
        int total=0;
        for(int i=1;i<=2*m;i++){
            if(curr+i-1 >= piles.size()){
                break;
            }
            total+=piles[curr+i-1];
            if(alice){
                maxi=max(maxi, total+memo(piles,curr+i,max(i,m),!alice,dp));
            }
            else{
                maxi=min(maxi, memo(piles,curr+i,max(i,m),!alice,dp));
            }
        }
        return dp[curr][m][alice] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        // return recur(piles,0,1,true);
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return memo(piles,0,1,true,dp);
    }
};