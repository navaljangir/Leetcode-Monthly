//s.c O(n)
//T.C : O(n)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> prevSum(nums.size());
        vector<int> afterSum(nums.size());
        long long preSum =0 ;
        long long laterSum =0 ;
        for(auto i : nums){
            laterSum+=i;
        }
        for(int i =0 ; i<nums.size();i++){
            prevSum[i]= preSum;
            preSum+=nums[i];
            afterSum[i]=laterSum-nums[i];
            laterSum-=nums[i];
        }
        vector<int> ans(nums.size());
        for(int i =0 ; i<nums.size();i++){
            if(i+1<nums.size()){
                int num1 = abs(nums[i]*i-prevSum[i]);
                int size =nums.size()-i-1;
                int num2 = abs(nums[i]*size - afterSum[i]);
                ans[i]=num1+num2;
            }else{
            int num1 = abs(nums[i]*i - prevSum[i]);
            ans[i]=num1;
            }
        }
        

        return ans;
    }
};
