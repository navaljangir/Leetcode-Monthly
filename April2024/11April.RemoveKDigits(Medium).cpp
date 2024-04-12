class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        string ans = "";
        for(int i =0 ; i<num.size();i++){
            if(ans.length()==0){
                ans.push_back(num[i]);
            }else{
                if(ans[ans.length()-1]>num[i] && k>0){
                    while(k>0 && ans.length()>0 && ans[ans.length()-1]>num[i]){
                        ans.pop_back();
                        k--;
                    }
                   ans.push_back(num[i]);
                }else{
                    ans.push_back(num[i]);
                }
            }
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        int i =0 ; 
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans = ans.substr(i);
        if(ans.length()==0){
            return "0";
        }
        return ans;
    }
};
