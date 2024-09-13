/*
right part not important ,,, use long long as mid*mid might go out of bound
*/

int solve(int n){
    int s=0;int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int ok=mid*mid;
        if(ok==n){
            return mid;
        }

        else if(ok>n){
            e=mid-1;
        }
        else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}