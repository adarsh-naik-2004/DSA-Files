/*
second line pe pivot dekh rahe ,,, s ya e dono return kar sakte hai     
*/


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