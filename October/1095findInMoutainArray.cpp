/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int pivotIndex = -1;
        int s= 0 ;

        int e  = mountainArr.length()-1;
        while(s<e){
        int mid = s + (e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s = mid+1;
            }else{
                e=mid;
            }
        } 
        pivotIndex = s;
        cout<<pivotIndex;
        int i=0 ; 
        int j = pivotIndex;
        int mini = INT_MAX;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(mountainArr.get(mid)==target){
                mini = min(mini , mid);
                break;
            }else if(mountainArr.get(mid)<target){
                i = mid+1; 
            }else{
                j= mid-1;
            }
        }
        i = pivotIndex;
        j = mountainArr.length()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
             if(mountainArr.get(mid)==target){
                mini = min(mini , mid);
                break;
            }else if(mountainArr.get(mid)<target){
                j = mid-11; 
            }else{
                i = mid+1;
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};
