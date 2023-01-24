class Solution {
public:;
    int n;
    
    pair<int,int> getcoordinate(int num){
        //int row_top=(num-1)/n;
        //int row_bottom=(n-1)-row_top;
        int r=n-1-(num-1)/n;
        int c=(num-1)%n;
        if((n%2==1 && r%2==1) || (n%2==0 && r%2==0)){
            c=(n-1)-c;
        }
        //return make_pair(row_bottom,c);
        return make_pair(r,c);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        int steps=0;
        queue<int>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        q.push(1);
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int x=q.front();
                q.pop();
                if(x==n*n){
                    return steps;
                }
                for(int i=1;i<=6;i++){
                    int val=x+i;
                    if(val>n*n){
                        break;
                    }
                    pair<int,int>coord=getcoordinate(val);
                    
                    int row=coord.first;
                    int col=coord.second;
                    
                    if(visited[row][col]==true)continue;
                    
                    visited[row][col]=true;
                    
                    if(board[row][col]==-1){
                        q.push(val);
                    }
                    else{
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
        
    }
};