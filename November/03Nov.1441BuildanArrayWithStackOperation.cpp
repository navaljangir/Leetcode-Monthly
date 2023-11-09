class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j= 1; 
        vector<string> ans;
        for(int i= 0 ;i<target.size();i++){
            if(target[i]!=j){
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
                i=i-1;
            }else{
                ans.push_back("Push");
                j++;
            }
        }
        return ans;
    }
};
