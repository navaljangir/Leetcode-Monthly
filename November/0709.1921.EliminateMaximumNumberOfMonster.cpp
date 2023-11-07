class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> timeToReach(dist.size()); 
        for(int i =0 ; i <dist.size();i++){
            timeToReach[i] = (double)dist[i]/speed[i];
        }
        sort(timeToReach.begin() , timeToReach.end());
        int ans =0 ; 
        for(int i = 0 ; i <timeToReach.size();i++){
            if(timeToReach[i]-ans<=0){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};


//Recusion Code - Time Limit Exceeded

class Solution {
public:
    unordered_map<int,bool> mp;
    int solve(vector<int>& dist , vector<int>& speed ,  bool charge){
        int ans =0 ; 
        for(int i =0 ; i <dist.size();i++){
            for(int j =0 ; j<dist.size();j++){
                if(dist[j]<=0 && mp[j]==false){
                    return ans;
                }
            }
            if(dist[i]>0){
                int prev= dist[i];
                dist[i]=0;
                mp[i]=true;
                for(int j = 0; j <dist.size();j++){
                    if(j!=i && mp[j]==false){
                        dist[j]=dist[j]-speed[j];
                    }
                }
                ans =max(ans , 1+ solve(dist, speed, false));
                dist[i]= prev;
                mp[i]=false;
                for(int j = 0; j <dist.size();j++){
                    if(j!=i && mp[j]==false){
                        dist[j]= dist[j]+speed[j];
                    }
                }
            }else{
                continue;
            }
        }
        return ans;
    }
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i = 0; i <dist.size();i++){
            mp[i]=false;
        }
        return solve(dist , speed, true);
    }
};
