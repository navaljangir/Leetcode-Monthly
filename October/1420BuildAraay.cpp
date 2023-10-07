class Solution {
public:
    long long mod = 1e9 +7;
    int solve(int n , int m , int k , vector<int>&v, int maxValue,int count,vector<vector<vector<int>>>&dp){
        if(v.size()==n && count<k){
            return 0;
        }
        if(v.size()==n && count==k){
            return 1;
        }
        if(count>k){
            return 0; 
        }
        if(dp[v.size()][maxValue][count]!=-1){
            return dp[v.size()][maxValue][count];
        }
        long long ans =0 ; 
        for(int i=1; i <=m;i++){
            v.push_back(i);
            if(i>maxValue){
            ans +=solve(n , m , k , v,i , count+1,dp);
            ans = ans%mod;
            v.pop_back();
            }else{
            ans +=solve(n,m,k,v,maxValue , count ,dp);
            ans = ans%mod;
            v.pop_back();
            }
        }
        return dp[v.size()][maxValue][count] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        if(k>m){
            return 0;
        }
        int ans =0 ;
        vector<vector<vector<int>>> dp(n+2 , vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        vector<int> v;
        return solve(n , m , k , v , 0 , 0 ,dp);
    }
};
