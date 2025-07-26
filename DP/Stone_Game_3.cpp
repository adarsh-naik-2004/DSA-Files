class Solution {
public:

    int recur(vector<int>& stone, int curr){
        if(curr>=stone.size()){
            return 0;
        }
        int ans = INT_MIN;
        int total=0;
        for(int i=1;i<=3;i++){
            if(curr+i-1>=stone.size()){
                break;
            }
            total+=stone[curr+i-1];
            ans=max(ans, total - recur(stone,curr+i));
        }
        return ans;
    }

    int memo(vector<int>& stone, int curr,vector<int>& dp){
        if(curr>=stone.size()){
            return 0;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        int ans = INT_MIN;
        int total=0;
        for(int i=1;i<=3;i++){
            if(curr+i-1>=stone.size()){
                break;
            }
            total+=stone[curr+i-1];
            ans=max(ans, total - memo(stone,curr+i,dp));
        }
        return dp[curr]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int ans = memo(stoneValue, 0,dp);
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};