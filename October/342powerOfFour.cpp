class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        int count = 0 ;
        int k = n ;
        while(n>0){
            if(n!=1 && n%4!=0){
                return false;
            }
            count++;
            n= n/4;
        }
        if(k<0 && count%2==0){
            return false;
        }
        return true;
    }
};
