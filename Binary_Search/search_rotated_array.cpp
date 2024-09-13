class Solution {
public:

int binarysearch(vector<int> arr,int target,int start ,int end){
    int mid=start+(end-start)/2; 
    while(start<=end){
        if(arr[mid]<target){
            start=mid+1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            return mid;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}


int pivot(vector<int> nums){
    int s=0;int e=nums.size()-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(nums[mid]>=nums[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int search(vector<int>& nums, int target) {
    int pivotindex=pivot(nums);

    if(nums.size()==1 && target==nums[0]){
        return 0;
    }

    else{
        if( pivotindex==0 || (target>=nums[0] && target<=nums[pivotindex-1])){
            return binarysearch(nums,target,0,pivotindex-1);
        }
        else{
            return binarysearch(nums,target,pivotindex,nums.size()-1);
        }
        }
    }
};