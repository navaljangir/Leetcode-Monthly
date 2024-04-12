class Solution {
public:
    bool solve(string s, int index, stack<int> st , vector<vector<int>>&dp){
        if(index>=s.length() && st.empty()){
            return true;
        }
        if(index>=s.length()){
            return false;
        }
        int size = st.size();
        if(dp[index][size]!=-1){
            return dp[index][size];
        }
        bool ans = false;
        if(s[index]=='('){
            st.push(index);
            ans = ans || solve(s , index+1 , st, dp);
        }
        if(s[index]=='*'){
            st.push(index);
            ans = ans || solve(s,  index+1 , st, dp);
            st.pop();
            ans = ans || solve(s , index+1 , st, dp);
            if(st.empty()==false){
                st.pop();
                ans = ans || solve(s , index+1 , st, dp);
            }
        }
        if(s[index]==')'){
            if(!st.empty()){
                st.pop();
                ans = ans || solve(s , index+1 , st, dp);
            }else{
                return false;
            }
        }
        return dp[index][size] = ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length()+1 , vector<int>(s.length()+1 , -1));
        stack<int> st;
        return solve(s,  0, st , dp);
    }
};
