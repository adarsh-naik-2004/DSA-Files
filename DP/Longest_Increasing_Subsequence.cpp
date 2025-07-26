class Solution {
public:

// prev = -1 thats why we are using prev+1 in dp

int recursion(vector<int>& nums,int curr,int prev){
    int n=nums.size();
    if(curr>=n){
        return 0;
    }
    int include=0;
    if(prev==-1 || nums[curr]>nums[prev]){
        include=1+recursion(nums,curr+1,curr);
    }
    int exclude=0+recursion(nums,curr+1,prev);

    int ans=max(include,exclude);
    return ans;

}
int memo(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
    int n=nums.size();
    if(curr>=n){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    int include=0;
    if(prev==-1 || nums[curr]>nums[prev]){
        include=1+memo(nums,curr+1,curr,dp);
    }
    int exclude=0+memo(nums,curr+1,prev,dp);
    int ans=max(include,exclude);
    dp[curr][prev+1]=ans;
    return dp[curr][prev+1];
}

int binarySearch(vector<int>& nums, int n){
    if(n==0){
        return 0;
    }
    vector<int>ans;
    ans.push_back(nums[0]);

    for(int i=1;i<n;i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}


    int lengthOfLIS(vector<int>& nums) {
        int curr=0;int prev=-1;int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(nums,curr,prev,dp);
    }
};