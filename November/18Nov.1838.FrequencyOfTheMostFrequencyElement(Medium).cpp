class Solution {
public:
    int binarySearch(vector<int>& nums , int start , int end , int&curridx , vector<long long>&prefixSum , int&k){
        int mid = start + (end-start)/2;
        int num = nums[curridx];
        int ans = curridx;
        while(start<=end){
            long long count =(curridx-mid+1);
            long long requiredSum =count*num;
            long long sum = prefixSum[curridx]-prefixSum[mid]+nums[mid];
            if(requiredSum-sum>k){
                start=mid+1;
            }else{
                ans = mid;
                end=mid-1;
            }
            mid=  start + (end-start)/2;
        }
        return (curridx-ans+1);
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector<long long> prefixSum(nums.size());
        prefixSum[0]=nums[0];
        for(int i = 1;i<nums.size();i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        int maxi =INT_MIN;
        for(int i =0 ; i<nums.size();i++){
            int windowSize = binarySearch(nums, 0 , i , i ,prefixSum , k);
            maxi = max(maxi , windowSize);
        }
        return maxi;
    }
};
