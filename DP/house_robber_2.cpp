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
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        if(n==1){
            return nums[0];
        }

        vector<int> lastnahi(nums.begin(),nums.end()-1);
        vector<int> firstnahi(nums.begin()+1,nums.end());
        return max(memo(lastnahi,0,dp1), memo(firstnahi,0,dp2));
    }
};