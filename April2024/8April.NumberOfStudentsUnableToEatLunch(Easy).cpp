class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       vector<int> v(2);
        for(int i= 0 ; i <students.size();i++){
            v[students[i]]++;
        }
        for(int i= 0; i < sandwiches.size();i++){
            if(v[sandwiches[i]]>0){
                v[sandwiches[i]]--;
            }else{
                return sandwiches.size()-i;
            }
        }
        return 0;
    }
};
