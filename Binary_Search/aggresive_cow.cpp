/*
minimum gap between cows should be maximum ,,,, unlike book allocation ---> maximum sum should be minimum

define search space ---> 0 to last-first ,,, then find mid which will be the atleast gap between cows

>= mid ,,,,
*/

bool solve(vector<int>&nums,int x,int mid){
    int n=nums.size();
    int c=1;
    int curr=nums[0];

    for(int i=0;i<n;i++){
        if(nums[i] - curr >= mid){
            c++;
            curr=nums[i];
        }
        if(c==x){
            return true;
        }
    }
    return false;
}





int binary(vector<int>& nums,int x){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int s=0;
    int e=nums[n-1]-nums[0];
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(solve(nums,x,mid)){
            ans=mid;
            s=mid+1; // maximize kar rahe 
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}


