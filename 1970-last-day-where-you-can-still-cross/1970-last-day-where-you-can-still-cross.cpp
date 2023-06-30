// class Solution {
// public:
//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
//     }
// };
class Solution {
public:

    
    bool pred(int mid,vector<vector<int>> grid, vector<vector<int>> &cell){
        for(int i=0;i<mid;i++){
            grid[cell[i][0]-1][cell[i][1]-1]=1;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==0){
                q.push({0,i});
                grid[0][i]=1;
            }
        
        }
         int n=grid.size();
         int m=grid[0].size();
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto top=q.front();
                q.pop();
                int x=top.first;
                int y=top.second;
                if(x==n-1)return true;
                if(x-1>=0&& grid[x-1][y]==0){
                    q.push({x-1,y});
                    grid[x-1][y]=1;
                }
                if(x+1<=n-1&& grid[x+1][y]==0){
                    q.push({x+1,y});
                    grid[x+1][y]=1;
                }
                if(y-1>=0&& grid[x][y-1]==0){
                    q.push({x,y-1});
                    grid[x][y-1]=1;
                }
                if(y+1<=m-1&& grid[x][y+1]==0){
                    q.push({x,y+1});
                    grid[x][y+1]=1;
                }

            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int> (col,0));
        int low=1;
        
        int high=row*col;

        int ans=-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(pred(mid,grid, cells)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};