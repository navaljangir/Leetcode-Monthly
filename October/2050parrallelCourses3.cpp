class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(time.size(),0);
        for(int i = 0 ; i <relations.size();i++){
            int u = relations[i][0];
            int v = relations[i][1];
            mp[u].push_back(v);
            indegree[v-1]++;
        }
        vector<int> maxTime(time.size(),0);
        queue<int> q;
        for(int i =0 ; i<time.size(); i++){
            if(indegree[i]==0){
                q.push(i);
                maxTime[i]=time[i];
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vector<int> v = mp[u+1];
            for(int i = 0; i<v.size();i++){
                maxTime[v[i]-1]=max(maxTime[v[i]-1] , maxTime[u]+time[v[i]-1]);
                indegree[v[i]-1]--;
                if(indegree[v[i]-1]==0){
                    q.push(v[i]-1);
                }
            }

        }
        int maxi = INT_MIN;
        for(int i = 0 ; i<maxTime.size();i++){
            maxi = max(maxi , maxTime[i]);
        }
        return maxi;
    }

};
