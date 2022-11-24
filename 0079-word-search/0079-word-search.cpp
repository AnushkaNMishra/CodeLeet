class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board, string word,int pos){
        int r=board.size();
        int c=board[0].size();
        int s=word.size();
        if(pos==s)return true;
        if(i<0 || j<0 || i>r-1 || j>c-1)return false;
        if(word[pos]!=board[i][j])return false;
        board[i][j]='0';
        bool up=dfs(i-1,j,board,word,pos+1);
        bool down=dfs(i+1,j,board,word,pos+1);
        bool right=dfs(i,j+1,board,word,pos+1);
        bool left=dfs(i,j-1,board,word,pos+1);
        board[i][j]=word[pos];
        return up || down || right || left;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[0].size();j++){
               if(dfs(i,j,board,word,0))return true;
           }
       }
        return false;
    }
};