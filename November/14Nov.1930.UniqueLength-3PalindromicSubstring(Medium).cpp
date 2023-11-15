//My first Intution
class Solution {
public:
    unordered_map<string,bool> mp;
    bool palin(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    int solve(string &s , string str, int i){
         if(str.length()==3){
            if(mp.find(str)==mp.end() && palin(str)){
                mp[str]=true;
                cout<<str<<" ";
            return 1;
            }
            return 0;
        }
        if(i>=s.length()){
            return 0;
        }
        if(str.length()>3){
            return 0;
        }
       
        int ans = 0;
        ans = ans+ solve(s , str+s[i] , i+1);
        ans = ans + solve(s,str, i+1);
        return ans;
    }
    int countPalindromicSubsequence(string s) {
            return solve(s , "" , 0);
    }
};


//y
