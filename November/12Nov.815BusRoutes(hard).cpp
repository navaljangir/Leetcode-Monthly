class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>> adj;
        for(int i= 0 ; i<routes.size();i++){
            for(int j = 0 ; j<routes[i].size();j++){
                adj[routes[i][j]].push_back(i);
            }   
        }
        queue<int> q;
        vector<bool> visited(501 , false);
        for(int i = 0 ;  i<adj[source].size();i++){
            q.push(adj[source][i]);
            visited[adj[source][i]]=true;
        }
        int busCount =1 ;
        while(!q.empty()){
            int size =q.size();
            while(size>0){
                int route = q.front();
                q.pop();
                for(int i =0 ; i <routes[route].size();i++){
                    if(routes[route][i]==target){
                        return busCount;
                    }
                    for(int j = 0 ;j<adj[routes[route][i]].size();j++){
                        if(visited[adj[routes[route][i]][j]]==false){
                            visited[adj[routes[route][i]][j]]=true;
                            q.push(adj[routes[route][i]][j]);
                        }
                    }
                }
                size--;
            }
        busCount++;
        }
        return -1;
    }
};
