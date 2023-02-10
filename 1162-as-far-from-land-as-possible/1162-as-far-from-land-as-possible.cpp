class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int count = 0;
        queue< pair<int,int> > Q;
        
        //put all 1s {} in Q
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col] == 1){
                    Q.push({row,col});
                }
            }
        }
        
        while(!Q.empty()){
            count++;
            int Qsize = Q.size();
            
        for(int i=0;i<Qsize;i++){
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();
                
            // up
            if(row-1 >= 0 && grid[row-1][col]!=1 ){
                grid[row-1][col]=1;
                Q.push({row-1,col});
            }
                
            // left
            if(col-1 >= 0 && grid[row][col-1]!=1 ){
                grid[row][col-1]=1;
                    Q.push({row,col-1});
            }
                
            // right
            if(col+1 <grid[0].size() && grid[row][col+1]!=1 ){
                grid[row][col+1]=1;
                    Q.push({row,col+1});
            }
                
            // down
            if(row+1 <grid.size() && grid[row+1][col]!=1 ){
                grid[row+1][col]=1;
                    Q.push({row+1,col});
            }
            }
        }
        
        return count<=1 ? -1 : count-1 ;
    }
};