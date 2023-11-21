class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> prefixSum(travel.size());
        prefixSum[0]=travel[0];
        int ans = 0;
        for(int i = 1; i<travel.size();i++){
            prefixSum[i]=prefixSum[i-1]+travel[i];
        }
        int pLastIndex = 0;
        int mLastIndex =0;
        int gLastIndex =0;
        for(int i =0 ; i<garbage.size();i++){
            for(auto j : garbage[i]){
                if(j=='P'){
                    pLastIndex = i;
                }
                if(j=='M'){
                    mLastIndex = i;
                }
                if(j=='G'){
                    gLastIndex = i;
                }
            }
            ans = ans + garbage[i].length();
        }
        if(pLastIndex-1>=0){
            ans = ans + prefixSum[pLastIndex-1];
        }
        if(mLastIndex-1>=0){
            ans = ans+ prefixSum[mLastIndex-1];
        }
        if(gLastIndex-1>=0){
            ans= ans + prefixSum[gLastIndex-1];
        }
        return ans;
    }
};
