class Solution {
public:

    // here simple lis by dp will not work so go with the ----> binary search approach
    // see the comp function carefully

    // int memo(vector<vector<int>>&env, int prev, int curr, vector<vector<int>>&dp){
    //     if(curr>=env.size()){
    //         return 0;
    //     }
    //     if(dp[prev+1][curr]!=-1){
    //         return dp[prev+1][curr];
    //     }
    //     int include = INT_MIN;
    //     if(prev==-1 || (env[prev][0]<env[curr][0] && env[prev][1]<env[curr][1])){
    //         include = 1+memo(env,curr,curr+1,dp);
    //     }
    //     int exclude = memo(env,prev,curr+1,dp);
    //     return dp[prev+1][curr] = max(include,exclude);
    // }

    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int binarySearch(vector<vector<int>>& nums, int n){
        // sort by w , if 2 equal then sort by h(descending)
        sort(nums.begin(),nums.end(),comp);
        if(n==0){
            return 0;
        }
        // run lis on h
        vector<int>ans;
        ans.push_back(nums[0][1]);

        for(int i=1;i<n;i++){
            if(nums[i][1]>ans.back()){
                ans.push_back(nums[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // return memo(envelopes,-1,0);
        // vector<vector<int>>dp(envelopes.size(),vector<int>(envelopes.size(),-1));
        return binarySearch(envelopes,envelopes.size());
    }
};