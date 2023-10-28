class Solution {
public:
int mod = 1e9+7;
    int solve(int&n ,string&s,vector<vector<int>>&dp, unordered_map<char,int>&mp){
        if(s.length()==n){
            return 1;
        }
        if(dp[mp[s[s.length()-1]]][s.length()]!=-1){
            return dp[mp[s[s.length()-1]]][s.length()];
        }
        long long ans= 0;
            if(s[s.length()-1] =='a'){
                s+='e';
                ans =( ans + solve(n , s, dp ,mp))%mod;
                s.pop_back();
            }else if(s[s.length()-1]=='e'){
                s+='a';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
                s+='i';
                ans =( ans + solve(n , s, dp ,mp))%mod;
                s.pop_back();
            }else if(s[s.length()-1]=='i'){
                s+='a';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
                s+='e';
                ans =( ans + solve(n , s, dp ,mp))%mod;
                s.pop_back();
                s+='o';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
                s+='u';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
            }else if(s[s.length()-1]=='o'){
                s+='i';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
                s+='u';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
            }else if(s[s.length()-1]=='u'){
                s+='a';
                ans =( ans + solve(n ,s, dp ,mp))%mod;
                s.pop_back();
            }
            return dp[mp[s[s.length()-1]]][s.length()] = ans;
    }
    int countVowelPermutation(int n) {
        vector<char> v= {'a','e','i','o','u'};
        vector<vector<int>> dp(5, vector<int>(n+1,-1));
        unordered_map<char,int> mp;
        for(int i = 0; i <v.size();i++){
            mp[v[i]]=i;
        }
        long long ans =0 ;
        for(int i =0 ; i<v.size();i++){
            string str ="";
            str+=v[i];
            long long getAns = solve(n, str , dp , mp)%mod;
            ans = (ans+getAns)%mod;
        }
        return ans%mod;
    }
};
