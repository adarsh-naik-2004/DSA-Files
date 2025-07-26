class Solution {
public:

    int recur(vector<int>& days, vector<int>& costs, int i){
        if(i>=days.size()){
            return 0;
        }

        int ok1 = recur(days,costs,i+1) + costs[0];

        int j=i;
        while(j<days.size() && days[j]<=(days[i]+7-1)){
            j++;
        }
        int ok2 = recur(days,costs,j)+costs[1];

        j=i;
        while(j<days.size() && days[j]<=(days[i]+30-1)){
            j++;
        }
        int ok3 = recur(days,costs,j)+costs[2];

        int ans = min(ok1,min(ok2,ok3));
        return ans;
    }

    int memo(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int ok1 = memo(days,costs,i+1,dp) + costs[0];

        int j=i;
        while(j<days.size() && days[j]<=(days[i]+7-1)){
            j++;
        }
        int ok2 = memo(days,costs,j,dp)+costs[1];

        j=i;
        while(j<days.size() && days[j]<=(days[i]+30-1)){
            j++;
        }
        int ok3 = memo(days,costs,j,dp)+costs[2];

        dp[i] = min(ok1,min(ok2,ok3));
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        // return recur(days,costs,i);
        int n = days.size();
        vector<int>dp(n+1,-1);
        return memo(days,costs,i,dp);
    }
};