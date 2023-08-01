class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char s='1';s<='9';s++){
                        if(isvalid(board,i,j,s)){
                            board[i][j]=s;
                            
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool isvalid(vector<vector<char>>& board,int row,int col,char s){
        for(int i=0;i<9;i++){
            if(board[row][i]==s || board[i][col]==s || board[3*(row/3)+i/3][3*(col/3)+i%3]==s)
                return false;
        }
        return true;
    }
};