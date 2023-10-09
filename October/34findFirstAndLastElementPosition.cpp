class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0 ;
        int j = nums.size()-1;
        int index =-1;
        int mid = i + (j-i)/2;
        while(i<=j){
            if(nums[mid]==target){
                index=mid;
                break;
            }else if(nums[mid]<target){
                i = mid+1;
            }else{
                j=mid-1;
            }
            mid = i + (j-i)/2;
        }
        if(index==-1){
            return {-1,-1}; 
        }
        int firstIndex =index;
        int lastIndex = index;
        while(firstIndex>=0 && nums[firstIndex]==target){
            firstIndex--;
        }
        while(lastIndex<nums.size() && nums[lastIndex]==target){
            lastIndex++;
        }
        firstIndex++;
        lastIndex--;
        return {firstIndex, lastIndex};
    }
};
