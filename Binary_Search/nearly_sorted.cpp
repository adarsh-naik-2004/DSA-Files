/*
search in nearly sorted ---> ek do element displaced hai  ,,,, normal sort is better (n log n)  ,,, whereas this method is (log n(n+1))

+2 ---> pheli wala checking already

*/

int nearly(vector<int>& nums,int target){
    int s=0;int e=nums.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid-1]==target && mid-1 >=0){
            return mid-1;
        }
        else if(nums[mid+1]==target && mid+1 < nums.size()){
            return mid+1;
        }
        else if(target >nums[mid]){
            s=mid+2;
        }
        else{
            e=mid-2;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}