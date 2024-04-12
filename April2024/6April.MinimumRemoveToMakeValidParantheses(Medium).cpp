class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        unordered_map<int,bool> mp;
        string ans = "";
        for(int i =0 ; i < s.length();i++){
            if(s[i]=='('){
                st.push({'(' , i});
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                mp[i] = true;
                }
            }
        }
        while(!st.empty()){
            int top = st.top().second;
            mp[top]= true;
            st.pop();
        }
        for(int i =0 ; i <s.length();i++){
            if(mp.find(i)==mp.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};
