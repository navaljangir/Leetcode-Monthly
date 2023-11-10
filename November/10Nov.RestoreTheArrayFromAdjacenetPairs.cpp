class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> v;
        unordered_map<int,vector<int>> mp;
        for(int i = 0 ; i <adjacentPairs.size();i++){
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int firstElement = -1;
        int size =0 ; 
        for(auto &i : mp){
            size++;
            if(i.second.size()==1){
                firstElement = i.first;
            }
        }
        v.push_back(firstElement);
        while(v.size()!=size){
            int num = v[v.size()-1];
            if(mp[num].size()==2){
                int first = mp[num][0];
                int second = mp[num][1];
                int n  = v.size()-2;
                if(v[n]==first){
                    v.push_back(second);
                }else{
                    v.push_back(first);
                }
            }else{
                int u = mp[num][0];
                v.push_back(u);
            }
        }
        return v;
    }   
};
