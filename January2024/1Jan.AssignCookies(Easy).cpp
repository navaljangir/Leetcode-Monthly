class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int count =0 ; 
        int j =0 ; 
        for(int i = 0 ; i <g.size();i++){
            if(j<s.size() && g[i]<=s[j]){
                count++;
                j++;
            }else{
                while(j<s.size() &&  g[i]>s[j]){
                    j++;
                }
                if(j<s.size() && g[i]<=s[j]){
                    count++;
                    j++;
                }
            }
        }
        return count;
    }
};
