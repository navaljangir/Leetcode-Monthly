class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> maxSum = nums; 
        priority_queue<pair<int,int>> q;
        q.push({nums[0] , 0});
        int maxi = maxSum[0];
        for(int i = 1;i<nums.size(); i++){
            while(!q.empty() && i-q.top().second>k){
                q.pop();
            }
            maxSum[i] = max(maxSum[i] , nums[i] + q.top().first);
            q.push({maxSum[i], i});
            maxi = max(maxi , maxSum[i]);
        }
        return maxi;
    }
};
