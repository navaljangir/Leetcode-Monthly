class Solution {
public:
    int solve(vector<int>&cost ,int n, int index,vector<int>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index+1]!=-1){
            return dp[index+1];
        }
        int take= INT_MAX;
        int notTake = INT_MAX;
        if(index==-1){
            take = solve(cost, n, index+1,dp ) ;
            notTake = solve(cost ,n,  index+2,dp);
        }else{
            take = cost[index]+ solve(cost , n, index+1,dp);
            notTake = cost[index] + solve(cost ,n,  index+2,dp);
        }
        return dp[index+1]=min(take,notTake);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return solve(cost , n , -1,dp);
    }
};
