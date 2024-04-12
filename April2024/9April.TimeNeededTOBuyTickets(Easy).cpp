class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i= 0; i < tickets.size();i++){
            q.push({tickets[i] , i});
        }
        int time =0 ;
        while(!q.empty()){
            int topCount = q.front().first;
            int topIndex = q.front().second;
            q.pop();
            time++;
            topCount--;
            if(topCount>0){
                q.push({topCount, topIndex});
            }
            if(topIndex==k && topCount==0){
                return time;
            }
        }
        return time;
    }
};
