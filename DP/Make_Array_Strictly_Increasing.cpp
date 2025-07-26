class Solution {
public:

    // prev as value not index and map instead of dp

    #define INF (1e9+1)
    int recur(vector<int>& arr1, vector<int>& arr2, int prev, int curr){
        if(curr>=arr1.size()){
            return 0;
        }
        int op1=INF;
        if(prev<arr1[curr]){
            op1 = recur(arr1,arr2,arr1[curr],curr+1);
        }
        int op2=INF;
        auto index = upper_bound(arr2.begin(),arr2.end(),prev);
        if(index!=arr2.end()){
            int ok=index-arr2.begin();
            op2=1+recur(arr1,arr2,arr2[ok],curr+1);
        }
        return min(op1,op2);
    }

    int memo(vector<int>& arr1, vector<int>& arr2, int prev, int curr, map<pair<int,int>,int>& mp){
        if(curr>=arr1.size()){
            return 0;
        }
        if(mp.find({prev,curr})!=mp.end()){
            return mp[{prev,curr}];
        }
        int op1=INF;
        if(prev<arr1[curr]){
            op1 = memo(arr1,arr2,arr1[curr],curr+1,mp);
        }
        int op2=INF;
        auto index = upper_bound(arr2.begin(),arr2.end(),prev);
        if(index!=arr2.end()){
            int ok=index-arr2.begin();
            op2=1+memo(arr1,arr2,arr2[ok],curr+1,mp);
        }
        return mp[{prev,curr}]=min(op1,op2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int>mp;
        int ans = memo(arr1,arr2,-1,0,mp);
        if(ans==INF){
            return -1;
        }
        return ans;
    }
};