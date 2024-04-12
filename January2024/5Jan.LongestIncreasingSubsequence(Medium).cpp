class Solution {
public:
    int solve(int i  , vector<int>&nums , int prev,  vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int include = 0;
        if(prev==-1 || nums[i]>nums[prev]){
            include = 1+ solve(i+1 , nums , i ,dp);
        }
        int exclude = solve(i+1 , nums , prev , dp);
        return dp[i][prev+1] = max(include , exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , -1));
        return solve(0 , nums , -1 , dp);
    }
};
