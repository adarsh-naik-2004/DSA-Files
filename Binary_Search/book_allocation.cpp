/*
partition ka sum maximum should be minimum ,,, define search space ---> 0 to end(sum of all elements) ,,, count ko 1 se start ,,, sum=nums[i]

basically ulta chalta hai ye ,,, "ans ye hai ki nhi"
*/

bool solve(vector<int>&nums,int x,int mid){
    int n=nums.size();
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]>mid){
            return false;
        }
        if(sum+nums[i] > mid){
            c++;
            sum=nums[i];
            if(c>x){
                return false;
            }
        }
        else{
            sum+=nums[i];
        }
    }
    return true;
}



int binary(vector<int>&nums,int x){
    int n=nums.size();
    int s=0;int e=0;int ans=0;
    for(int i=0;i<n;i++){
        e+=nums[i];
    }
    int mid=s+(e-s)/2;
    while(s<=e){
        if(x>n){
            return -1;
        }
        if(solve(nums,x,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
