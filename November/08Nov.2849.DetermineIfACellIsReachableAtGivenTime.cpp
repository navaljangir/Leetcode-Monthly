//TLE
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // if(sx==)
        if(fx==sx && sy==fy && t==1){
            return false;
        }
        if(sx==fx){
            return abs(fy-sy)<=t;
        }
        if(sy==fy){
            return abs(fx-sx)<=t;
        }
        if(fy<sy){
            int count =0 ; 
            if(fx<sx){
                while(fy!=sy && sx!=fx){
                    sy--;
                    sx--;
                    count++;
                }
            }else{
                //fx>sx
                while(fy!=sy && sx!=fx){
                    sy--;
                    sx++;
                    count++;
                }
            }
            if(fx==sx){
                return (count+abs(fy-sy)<=t);
            }
            if(fy==sy){
                return (count+abs(fx-sx)<=t);
            }
        }else{
            //fy>sy
            int count =0 ; 
            if(fx<sx){
                while(fy!=sy && sx!=fx){
                    sx--;
                    sy++;
                    count++;
                }
            }else{
                //fx>sx
                while(fy!=sy && sx!=fx){
                    sy++;
                    sx++;
                    count++;
                }
            }
            if(fx==sx){
                return (count+abs(fy-sy)<=t);
            }
            if(fy==sy){
                return (count+abs(fx-sx)<=t);
            }
        }
        return false;
    }
};



//Optimised
//T.C = O(1) && S.C = o(1) 
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && fy==sy && t==1){
            return false;
        }
        int ans = max(abs(fy-sy) , abs(sx-fx));
        return ans<=t;
    }
};
