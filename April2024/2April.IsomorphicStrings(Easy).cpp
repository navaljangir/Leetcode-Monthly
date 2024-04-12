class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> mapped;
        for(int i =0 ;  i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                if(mapped.find(t[i])==mapped.end()){
                mp[s[i]] = t[i];
                mapped[t[i]] = true;
                }else{
                    return false;
                }
            }else{
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
