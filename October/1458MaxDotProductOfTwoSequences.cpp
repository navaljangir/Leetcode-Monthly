class Solution {
public:
    int solve(vector<int>&nums1 , vector<int>&nums2 , int i , int j,vector<vector<int>>&dp){
        if(i>=nums1.size()){
            return -1e9;
        }
        if(j>=nums2.size()){
            return -1e9;
        }
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        int ans = INT_MIN;
        int maxi = nums1[i]*nums2[j];
        ans = max(maxi , ans);
        int res = maxi + solve(nums1 , nums2 , i+1, j+1,dp);
        ans = max(ans , res);
        ans = max(ans , solve(nums1 , nums2, i+1 , j,dp));
        ans = max(ans , solve(nums1 , nums2 , i, j+1,dp));
        return dp[i][j] = ans;

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1 , vector<int>(nums2.size()+1, -1e9));
       return solve(nums1,  nums2, 0, 0,dp);
    }
};
