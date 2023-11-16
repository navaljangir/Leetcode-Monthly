class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin() , nums.end());
        for(int i= 0 ; i<nums.size();i++){
            string s = nums[i];
            int count =0;
            int number = 0;
            int j = s.size()-1; 
            while(j>=0){
                int num = s[j]-'0';
                int digit = (num%10) * pow(2,count);
                number +=digit;
                count++;
                j--;
            }
            if(number!=i){
                string str = "" ; 
                int digit =i;
                while(digit>0){
                    str = str+to_string(digit%2);
                    digit = digit/2;
                }
                reverse(str.begin() , str.end());
                int size = nums[0].size() - str.size();
                while(size>0){
                    str = '0' + str;
                    size--;
                }
                return str;
            }
        }
        string str = "" ; 
        int size = nums.size();
        while(size>0){
            str+='1';
            size--;
        }
        return str;
    }
};
