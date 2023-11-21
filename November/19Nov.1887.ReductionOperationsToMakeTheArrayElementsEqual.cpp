class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans =0;
        for(int i =nums.size()-1;i>=0;i--){
            int j = i;
            int prev = nums[i];
            ans+= nums.size()-(j+1);
            while(j>=0 && nums[i]==nums[j]){
                j--;
            }
            i =j+1;
        }
        return ans;
    }
};
