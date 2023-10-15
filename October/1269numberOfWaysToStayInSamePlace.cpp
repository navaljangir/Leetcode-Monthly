class Solution {
public:
    long long mod= 1e9+7;
    int solve(int&arrLen , int steps, int i ,vector<vector<int>>&dp){
        if(i<0){
            return 0;
        }
        if(i>=arrLen){
            return 0;
        }
        if(steps==0 && i==0){
            return 1;
        }
        if(i>steps){
            return 0;
        }
        if(dp[i][steps]!=-1){
            return dp[i][steps];
        }
        return dp[i][steps]=((solve(arrLen , steps-1 , i+1 ,dp))%mod+(solve(arrLen , steps-1 , i-1 , dp))%mod+(solve(arrLen , steps-1 , i , dp))%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps/2+1 , vector<int>(steps+1 , -1));
        return solve(arrLen , steps , 0,dp);
    }
};
