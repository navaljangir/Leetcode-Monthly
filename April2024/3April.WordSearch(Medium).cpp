class Solution {
public:
    bool solve(vector<vector<char>>&board , int i , int j , int index, string&word , bool found ,vector<vector<int>>&visited){
        if(index>=word.length()){
            return true;
        }
        if(i>=board.size() || i<0 || j<0 || j>=board[0].size()){
            return false;
        }
        if(visited[i][j]==1){
            return false;
        }
        bool ans1 = false;
        bool ans2 = false;
        bool ans3 = false;
        bool ans4 = false;
        bool ans5 = false;
        bool ans6 = false;
        if(board[i][j] ==word[index]){
            visited[i][j] = 1;
            ans1 = ans1 || solve(board, i ,j+1 ,  index+1 , word , true , visited );
            ans2 = ans2 || solve(board , i+1 , j , index+1 , word , true , visited);
            ans3 = ans3 || solve(board , i-1 , j, index+1  , word,  true , visited );
            ans4 = ans4 || solve(board, i , j-1 , index+1 , word , true , visited );
            visited[i][j]= 0;
            if(ans1 || ans2 || ans3 || ans4){
                return true;
            }
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0 ; i <board.size();i++){
            vector<vector<int>> visited(board.size() , vector<int>(board[0].size() , 0));
            for(int j =0 ; j<board[0].size();j++){
                if(solve(board , i, j , 0 , word, false, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
