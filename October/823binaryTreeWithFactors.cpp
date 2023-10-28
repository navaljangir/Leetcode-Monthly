class Solution {
public:
int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        unordered_map<int,long long> mp;
        for(int i =0; i<arr.size();i++){
            mp[arr[i]]=1;
            for(int j = 0; j <i; j++){
                if(arr[i]%arr[j]==0){
                    if(mp.find(arr[i]/arr[j])!=mp.end()){
                        mp[arr[i]]=(mp[arr[i]]+mp[arr[j]]*mp[arr[i]/arr[j]])%mod;
                    }
                }
            }
        }
        long long ans = 0; 
        for(auto i : mp){
            ans = (ans+i.second)%mod;
        }
        return ans;
    }
};
