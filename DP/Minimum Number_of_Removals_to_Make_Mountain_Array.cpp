// --> longest increasing subsequence

class Solution {
public:

    // see how the ls is made in binarysearch function
    // see all the indexs carefully

    int binarysearch(vector<int>& arr, int n, vector<int>& ls){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(arr[0]);
        ls.push_back(1);
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
                ls.push_back(ans.size());
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
                ls.push_back(index+1);
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis,lds;
        binarysearch(nums,nums.size(),lis);
        reverse(nums.begin(),nums.end());
        binarysearch(nums,nums.size(),lds);

        int bigmountain = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(lis[i] ==1 || lds[nums.size()-1-i]==1){
                continue;
            }
            bigmountain=max(bigmountain, lis[i]+lds[nums.size()-1-i]-1);
        }
        return nums.size()-bigmountain;
    }
};