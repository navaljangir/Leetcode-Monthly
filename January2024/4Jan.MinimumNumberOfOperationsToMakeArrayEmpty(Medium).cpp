class Solution {
public:
    unordered_map<int,int> dp;
    int solve(int num){
        if(num<0){
            return 1e9;
        }
        
        if(num==0){
            return 0;
        }
        if(dp.find(num)!=dp.end()){
            return dp[num];
        }
        int ans1 = 1+solve(num-3);
        int ans2 = 1 + solve(num-2);
        return dp[num]  = min(ans1 , ans2);
    }
    int minOperations(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans =0; 
        for(int i = 0 ; i<nums.size();i++){
            int j =i ; 
            int count =0 ;
            while(j<nums.size() && nums[i]==nums[j]){
                j++;
                count++;
            }
            if(count==1){
                cout<<count;
                return -1;
            }
            int getMin = solve(count);
            ans+=getMin;
            i = j-1;
        }
        return ans;
    }
};
