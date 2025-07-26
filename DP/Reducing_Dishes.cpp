class Solution {
public:

    int recur(vector<int>& sat, int i, int time){
        if(i>=sat.size()){
            return 0;
        }
        int include = time*sat[i] + recur(sat, i+1, time+1);
        int exclude = recur(sat, i+1, time);

        return max(include, exclude);
    }

    int memo(vector<int>& sat, int i, int time, vector<vector<int>>& dp){
        if(i>=sat.size()){
            return 0;
        }
        if(dp[i][time]!=-1){
            return dp[i][time];
        }
        int include = time*sat[i] + memo(sat, i+1, time+1, dp);
        int exclude = memo(sat, i+1, time, dp);

        return dp[i][time] = max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return recur(satisfaction, 0, 1);
        vector<vector<int>>dp(satisfaction.size(), (vector<int>(satisfaction.size()+1,-1)));
        return memo(satisfaction, 0, 1, dp);
    }
};