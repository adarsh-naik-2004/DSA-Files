/*
kisko ---> dividend ,,, kisse ---> divisor ,,,answer ---> quotient

quotient*divisor + rem = dividend 

quotient*divisor <= dividend

*/
int solve(int dividend,int divisor){
    int s=0;int e=dividend;
    int ans=0;
    int mid=s+(e-s);
    while(s<=e){
        if(mid*divisor==dividend){
            return mid;
       }
       if(mid*divisor > dividend){
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

