class Solution {
public:

    bool memo(vector<int>& nums, vector<vector<int>>& dp, int n, int target){
        if(target==0){
            return true;
        }
        if(n == 0){
            if(nums[0] == target){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        bool include = false;
        if(nums[n] <= target){
            include = memo(nums,dp,n-1,target-nums[n]);
        }
        bool exclude = memo(nums,dp,n-1,target);

        dp[n][target] = include || exclude;

        return dp[n][target]; 
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(); int target = 0;
        for(auto i: nums){
            target+=i;
        }
        if(target%2!=0){
            return false;
        }
        target/=2;
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return memo(nums,dp,n-1,target);
    }
};