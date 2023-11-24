class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int valueCount =piles.size()/3;
        bool toTake = false;
        int ans= 0 ;
        for(int i =piles.size()-1;i>=0;i--){
            if(toTake==true && valueCount>0){
                ans+=piles[i];
                valueCount--;
                toTake =false;
            }else{
                toTake =true;
            }
        }
        return ans;
    }
};
