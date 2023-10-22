class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k ;
        int mini = nums[k];
        int maxi = nums[k];
        while(i>=0 && j<nums.size()){
            if(i==0 || (i-1>=0 && j+1<nums.size() && nums[i-1]<nums[j+1])){
                j++;
            }else{
                i--;
            }
            if(i>=0 && j<nums.size()){
            mini = min(mini , min(nums[i], nums[j]));
            maxi = max(maxi , mini*(j-i+1));
            }
        }
        return maxi;
    }
};
