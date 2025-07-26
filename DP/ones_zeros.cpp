class Solution {
public:
    void convertStrsToNumStrs(vector<string>& strs, vector<pair<int, int>>& numStrs) {
        for (auto str : strs) {
            int zeros = 0, ones = 0;
            for (auto ch : str) {
                if (ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int solve(vector<pair<int, int>>& numStrs, int i, int m, int n) {
        if (i == numStrs.size()) return 0;
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0)
            include = 1 + solve(numStrs, i + 1, m - zeros, n - ones);
        exclude = solve(numStrs, i + 1, m, n);
        return max(include, exclude);
    }

    int memo(vector<pair<int, int>>& numStrs, int i, int m, int n, vector<vector<vector<int>>>& dp){
        if (i == numStrs.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0)
            include = 1 + memo(numStrs, i + 1, m - zeros, n - ones, dp);
        exclude = memo(numStrs, i + 1, m, n, dp);
        dp[i][m][n] = max(include, exclude);
        return dp[i][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs;
        convertStrsToNumStrs(strs, numStrs);
        // return solve(numStrs, 0, m, n);

        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        return memo(numStrs, 0, m, n, dp);
    }
};
