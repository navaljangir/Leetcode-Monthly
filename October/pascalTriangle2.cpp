class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr;
        vector<int> v;
        if(rowIndex==0){
            v.push_back(1);
            arr.push_back(v);
            return arr[0];
        }
          for(int i=0;i<2;i++){
              v.push_back(1);
              arr.push_back(v);
          }
        for(int i=2;i<=rowIndex;i++){
                vector<int> storeElement(i+1);
                storeElement[0]=1;
                storeElement[i]=1;
                int j=1;
                for(int k=0;k<i-1;k++){
                    storeElement[j]=arr[i-1][k]+arr[i-1][k+1];
                    j++;
                }
                arr.push_back(storeElement);
        }
        return arr[rowIndex]; 
    }
};
