class Solution {
public:
    int mod = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int ,vector<int>> mp;
        for(int i=0 ; i<nums.size();i++){
            int num = nums[i];
            int rev =0;
            while(num>0){
                rev = rev*10+num%10;
                num = num/10;
            }
            mp[nums[i]-rev].push_back(i);
        }
        int ans = 0;
        for(auto i : mp){
            if(i.second.size()>1){
                int size = i.second.size()-1;
                while(size>0){
                    ans =( ans+size)%mod;
                    size--;
                }
            }
        }
        return ans;
    }
};
