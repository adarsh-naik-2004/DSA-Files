class Solution {
public:

   // see the if condition carefully, its like if one string empty then add all the characters of the other string

    int recur(string& s1, string& s2, int i, int j){
        int costs = 0;
        if(i==s1.size() || j==s2.size()){
            for(int x = i; x < s1.size(); x++){
                costs+=s1[x];
            }
            for(int x = j; x < s2.size(); x++){
                costs+=s2[x];
            }
            return costs;
        }

        else if(s1[i]==s2[j]){
            costs = recur(s1,s2,i+1,j+1);
        }
        else{
            int first = s1[i] + recur(s1,s2,i+1,j);
            int second = s2[j] + recur(s1,s2,i,j+1);
            costs = min(first,second);
        }
        return costs;
    }

    int memo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        int costs = 0;
        if(i==s1.size() || j==s2.size()){
            for(int x = i; x < s1.size(); x++){
                costs+=s1[x];
            }
            for(int x = j; x < s2.size(); x++){
                costs+=s2[x];
            }
            return costs;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        else if(s1[i]==s2[j]){
            costs = memo(s1,s2,i+1,j+1,dp);
        }
        else{
            int first = s1[i] + memo(s1,s2,i+1,j,dp);
            int second = s2[j] + memo(s1,s2,i,j+1,dp);
            costs = min(first,second);
        }
        return dp[i][j] = costs;
    }

    int minimumDeleteSum(string s1, string s2) {
        // return recur(s1, s2, 0, 0);

        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(), -1));
        return memo(s1,s2,0,0,dp);
    }
};