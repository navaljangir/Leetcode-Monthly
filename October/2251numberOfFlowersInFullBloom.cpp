class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start; 
        vector<int> end;
        vector<int> ans;
        for(int i=0 ; i <flowers.size();i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(end.begin() , end.end());
        sort(start.begin() , start.end());
        for(int i =0 ; i<people.size();i++){
            int bloomedUp = upper_bound(start.begin() , start.end() , people[i]) - start.begin();
            int bloomedDown = lower_bound(end.begin() , end.end() , people[i]) - end.begin();
            ans.push_back(bloomedUp - bloomedDown);
        }
        return ans;
    }
};
