class Solution {
public:

    // go from one balloon and adding other balloons one by one ,, that is bottom up approach

    int recur(vector<int>& nums, int start, int end){
        if(start > end){
            return 0;
        }
        int coins=INT_MIN;
        for(int i=start;i<=end;i++){
            coins=max(nums[start-1]*nums[i]*nums[end+1]+recur(nums, start,i-1)+recur(nums,i+1,end) , coins);
        }
        return coins;
    }

    int memo(vector<int>& nums, int start, int end, vector<vector<int>>& dp){
        if(start > end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int coins=INT_MIN;
        for(int i=start;i<=end;i++){
            coins=max(nums[start-1]*nums[i]*nums[end+1]+memo(nums, start,i-1,dp)+memo(nums,i+1,end,dp) , coins);
        }
        return dp[start][end]=coins;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return memo(nums,1,nums.size()-2,dp);
        // return recur(nums,1,nums.size()-2);
    }
};