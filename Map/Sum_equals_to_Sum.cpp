class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<int,bool> mp;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=a[i]+a[j];
                
                if(mp.find(sum)!=mp.end()){
                    return true;
                }
                else{
                    mp[sum]=true;
                }
            }
        }
        return false;
    }
};
