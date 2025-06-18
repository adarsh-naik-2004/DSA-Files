class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;int n=piles.size();int final=0;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int top=pq.top();
            int ans=ceil(top/2.0);
            pq.pop();
            pq.push(ans);
            k--;
        }
        while(!pq.empty()){
            int ans1=pq.top();
            pq.pop();
            final+=ans1;
        }
        return final;
    }
};