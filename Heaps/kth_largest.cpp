class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;

        int ok = k;
        int i = 0;
        while(ok){
            pq.push(nums[i]);
            ok--;
            i++;
        }
        int hi = k;
        while(hi < nums.size()){
            if(nums[hi] > pq.top()){
                pq.pop();
                pq.push(nums[hi]);
            }
            hi++;
        }
        return pq.top();
    }
};