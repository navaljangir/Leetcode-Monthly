//BruteForce 
class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string s1 = "";
       string s2 = "";
       int i =0 ;
       while(i<s.length()){ 
          if(s[i]!='#'){
              s1+=s[i];
          }else{
              if(s1.length()!=0)
              s1.pop_back();
          }
          i++;
       }
       i=0;
       while(i<t.length()){
           if(t[i]!='#'){
               s2+=t[i];
           }else{
               if(s2.length()!=0)
               s2.pop_back();
           }
           i++;
       }
       return s1==s2;
    }
};
