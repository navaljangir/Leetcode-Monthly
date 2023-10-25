class Solution {
public:
    int solve(int n , int k ){
        if(n==1 || k==1){
            return 0; 
        }else if(k<=(pow(2,n-1)/2)){
            return solve(n-1, k);
        }else{
            return !solve(n-1 , k-(pow(2,n-1)/2));
        }
    }
    int kthGrammar(int n, int k) {
       return solve(n , k );
    }
};
