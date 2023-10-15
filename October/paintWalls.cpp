class Solution {
public:
    int solve(vector<int>&cost , vector<int>&time ,int i , int totalTime,vector<vector<int>>&dp ){
         if(totalTime<=0){
            return 0;
        }
        if(i>=time.size()){
            return 1e9;
        }
        if(dp[i][totalTime]!=-1){
            return dp[i][totalTime];
        }
        int notTake = solve(cost , time , i+1 , totalTime,dp);
        int take= cost[i]+solve(cost,  time , i+1 ,totalTime-1-time[i],dp);
        return dp[i][totalTime]= min(take, notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size()+1 ,vector<int>(cost.size()+2 , -1));
        return solve(cost, time, 0 , cost.size() ,dp);
    }
};
