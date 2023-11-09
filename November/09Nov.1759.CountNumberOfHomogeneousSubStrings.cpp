class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        long long ans =0 ;
        cout<<s.length();
        for(int i =0 ; i <s.length();i++){
            string str ="";
            int j =i ; 
            while(i<s.length() && s[j]==s[i]){
                str+=s[i];
                i++;
            }
            long long len = str.length();
            while(len>0){
                ans = (ans+ len)%mod;
                len--;
            }
            i--;
        }
        return ans;
    }
};

//shorter
class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        long long ans =0 ;
        cout<<s.length();
        for(int i =0 ; i <s.length();i++){
            string str ="";
            int j =i ;
            while(i<s.length() && s[j]==s[i]){
                str+=s[i];
                ans =(ans+str.length())%mod;
                i++;
            }
            i--;
        }
        return ans;
    }
};
