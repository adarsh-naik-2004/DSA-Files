class Solution {
public:
vector<int> solve(vector<int>& nums,int k,int x){
    int l=0;int h=nums.size()-1;
    while(h-l>=k){
        if(x-nums[l]>nums[h]-x){
            l++;
        }
        else{
            h--;
        }
    }
    vector<int> ans;
    for(int i=l;i<=h;i++){
        ans.push_back(nums[i]);
    }
    return ans;
}

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return solve(arr,k,x);
    }
};


Method 2 ----> 