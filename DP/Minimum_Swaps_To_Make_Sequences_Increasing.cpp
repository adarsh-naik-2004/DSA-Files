class Solution {
public:

    // do not make 3d dp , instead use 2d dp with isswaped 

    int recur(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2){
        if(i >= nums1.size()){
            return 0;
        }
        int include = INT_MAX; int exclude = INT_MAX;
        if(p1 < nums2[i] && p2 < nums1[i]){
            include = 1 + recur(nums1, nums2, i+1, nums2[i], nums1[i]);
        }
        if(p1 < nums1[i] && p2 < nums2[i]){
            exclude = recur(nums1, nums2, i+1, nums1[i], nums2[i]);
        }
        return min(include, exclude);
    }

    int memo(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2, vector<vector<int>>& dp, int isswaped){
        if(i >= nums1.size()){
            return 0;
        }
        if(dp[i][isswaped] != -1){
            return dp[i][isswaped];
        }
        int include = INT_MAX; int exclude = INT_MAX;
        if(p1 < nums2[i] && p2 < nums1[i]){
            include = 1 + memo(nums1, nums2, i+1, nums2[i], nums1[i], dp, 1);
        }
        if(p1 < nums1[i] && p2 < nums2[i]){
            exclude = memo(nums1, nums2, i+1, nums1[i], nums2[i], dp, 0);
        }
        return dp[i][isswaped] = min(include, exclude);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return recur(nums1, nums2, 0, -1, -1);
        vector<vector<int>>dp(nums1.size(),vector<int>(2, -1));
        return memo(nums1, nums2, 0, -1, -1, dp, 0);
    }
};