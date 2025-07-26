class Solution {
public:

    int memo(vector<int>& nums, int i, vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int include = memo(nums,i+2,dp)+nums[i];
        int exclude=memo(nums,i+1,dp);
        dp[i] = max(include,exclude);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return memo(nums,0,dp);
    }
};