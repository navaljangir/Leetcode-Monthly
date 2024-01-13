class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowelCount= 0;
        for(int i = 0 ;i<s.length();i++){
            if(i<s.length()/2){
                 if(s[i]=='A' || s[i]=='a' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                    vowelCount++;
                }
            }else{
                if(s[i]=='A' || s[i]=='a' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                    vowelCount--;
                }
            }
        }
        if(vowelCount==0){
            return true;
        }
        return false;
    }
};
