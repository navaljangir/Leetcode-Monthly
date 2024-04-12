class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        for(int i= 0 ; i <nums.size();i++){
            mp[nums[i]]++;
            maxi = max(mp[nums[i]] , maxi);
        }
        vector<vector<int>> v(maxi);
        for(auto i : mp){
            int j = i.second;
            int k = 0;
            while(j>0){
                v[k].push_back(i.first);
                k++;
                j--;
            }
        }
        return v;
    }
};
