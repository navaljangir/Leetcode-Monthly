class Solution {
public:
    string palindromicString(string s, int i, int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        if(i==j){
            return s.substr(i,1);
        }else{
            return s.substr(i+1 , j-i-1);
        }
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i =0 ; i<s.length(); i++){
            string str = palindromicString(s , i , i+1);
            if(ans.length()<str.length()){
                ans= str;
            }
            str = palindromicString(s, i , i );
            if(ans.length()<str.length()){
                ans= str;
            }
        }
        return ans;
    }
};
