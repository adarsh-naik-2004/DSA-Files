class Solution{
  public:
    int maxLen(int arr[], int N)
    {
       unordered_map<int,int> mp;
       int csum=0;
       int ans=0;
       for(int i=0;i<N;i++){
           int val=arr[i]==0 ? -1 : 1;
           csum+=val;
           if(csum==0){
               ans=max(ans,i+1);
           }
           else if(mp.find(csum) == mp.end()){
               mp[csum]=i;
           }
           else{
               ans=max(ans,i-mp[csum]);
           }
       }
       return ans;
    }
};