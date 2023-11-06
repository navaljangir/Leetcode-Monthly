class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> q;
        int maxi = INT_MIN;
        for(int i =0 ; i<arr.size();i++){
            q.push_back(arr[i]);
            maxi = max(maxi , arr[i]);
        }
        int count= 0 ; 
        int prev=-1;
        while(count<k){
            int first = q.front();
            q.pop_front();
            int second = q.front();
            q.pop_front();
            int mini = 0;
            if(first<second){
                if(second==maxi){
                    return maxi;
                }
                q.push_front(second);
                if(prev==second || prev==-1){
                    prev=second;
                    count++;
                }else{
                    prev = second;
                    count = 1;
                }
                q.push_back(first);
            }else{
                if(first==maxi){
                    return maxi;
                }
                //winner is first;
                q.push_front(first);
                q.push_back(second);
                if(prev==first || prev==-1){
                    prev=first;
                    count++;
                }else{
                    prev=first;
                    count=1;
                }
            }
        }
        return prev;
    }
};
