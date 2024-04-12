class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =0;
        int prev =0 ;
        for(int i =0 ; i <bank.size();i++){
            string s = bank[i];
            int secCount =0 ;
            for(int j = 0 ; j <s.length();j++){
                if(s[j]=='1'){
                    secCount++;
                }
            }
            if(secCount>0){
                ans+=(secCount*prev);
                prev = secCount;
            }
        }     
        return ans;
    }
};
