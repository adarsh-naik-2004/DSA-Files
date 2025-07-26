class Solution {
public:

    int recur(vector<int>& nums, int target, int i){
        if(i==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int plus = recur(nums,target+nums[i],i+1);
        int minus = recur(nums,target-nums[i],i+1);
        return plus+minus; 
    }

    int memo(vector<int>& nums, int target, int i, map<pair<int,int>,int>& dp){
        if(i==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp.find({i, target})!=dp.end()){
            return dp[{i,target}];
        }
        int plus = memo(nums,target+nums[i],i+1,dp);
        int minus = memo(nums,target-nums[i],i+1,dp);
        dp[{i,target}] = plus+minus;
        return dp[{i,target}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return recur(nums,target,0);
        map<pair<int,int>,int> dp;
        return memo(nums,target,0,dp);
    }
}; 