class Graph {
public:
    unordered_map<int,vector<int>> adj;
    map<pair<int,int> , int> cost;
    int size ;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        size= n;
        for(int i = 0; i <edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            cost[{edges[i][0],edges[i][1]}] = edges[i][2];
        }
    }
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back(edge[1]);
        cost[{edge[0] , edge[1]}] = edge[2];
    }
    int shortestPath(int node1, int node2) {
        vector<int> result(size , INT_MAX);
        result[node1]=0;
        pq.push({0 , node1});
        while(!pq.empty()){
            int u = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &i : adj[node]){
                int adjNode = i;
                int pathCost = cost[{node , i }];
                if(u + pathCost <result[adjNode]){
                    result[adjNode] = u + pathCost;
                    pq.push({u + pathCost , adjNode});
                }
            }
        }
        if(result[node2]==INT_MAX){
            return -1;
        }
        return result[node2];
    }

};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
