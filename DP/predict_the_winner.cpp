class Solution {
public:

    int memo(vector<int>& nums,int start, int end, vector<vector<int>>& dp){
        if(start==end){
            return nums[end];
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int first = nums[start] - memo(nums,start+1,end,dp);
        int last = nums[end] - memo(nums,start,end-1,dp);

        dp[start][end] = max(first,last);
        return dp[start][end];
    }

    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return memo(nums,0,nums.size()-1,dp) >=0 ? true:false;
    }
};