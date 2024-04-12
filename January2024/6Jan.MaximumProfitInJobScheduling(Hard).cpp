class Solution {
public:
    int solve(int index , vector<pair<pair<int,int>,int>>&v , vector<int>&startTime , vector<int>&dp){
        if(index>=v.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int i= lower_bound(startTime.begin() , startTime.end() ,  v[index].first.second)-startTime.begin();
        int include = v[index].second + solve(i , v ,startTime ,  dp);
        int exclude = solve(index+1 ,v , startTime, dp);
        return dp[index]= max(include , exclude);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> v;
        for(int i =0 ; i <startTime.size(); i++){
            v.push_back({{startTime[i] , endTime[i]} , profit[i]});
        }
        sort(v.begin() , v.end());
        sort(startTime.begin() , startTime.end());
        vector<int> dp(startTime.size()+1 , -1);
        return solve(0 , v ,startTime ,  dp);
    }
};
