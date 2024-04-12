class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans = "";
        string lastans = "";
        for(int i = 0 ; i <s.length();i++){
            if(s[i]==' '){
                if(ans.length()!=0)
                lastans = ans;
                ans = "";
                continue;
            }
            ans+=s[i];
        }
        if(ans.length()==0){
            return lastans.length();
        }
        return ans.length();
    }
};
