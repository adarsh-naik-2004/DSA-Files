class Solution {
public:
    bool canPlace(const vector<int>& below, const vector<int>& above) {
        return below[0] <= above[0] && below[1] <= above[1] && below[2] <= above[2];
    }

    int memo(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>>&dp){
        int n=cuboids.size();
        if(curr>=n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || canPlace(cuboids[prev],cuboids[curr])){
            include=cuboids[curr][2]+memo(cuboids,curr+1,curr,dp);
        }
        int exclude=0+memo(cuboids,curr+1,prev,dp);
        int ans=max(include,exclude);
        dp[curr][prev+1]=ans;
        return dp[curr][prev+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto&i : cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());

        int curr=0;int prev=-1;int n=cuboids.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return memo(cuboids,curr,prev,dp);
    }
};