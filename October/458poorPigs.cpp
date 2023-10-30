class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trials = minutesToTest/minutesToDie+1;
        int ans =0 ; 
        int n = pow(trials, ans);
        while(n<buckets){
            ans++;
            n = pow(trials,ans);
        }     
        return ans;
    }
};
