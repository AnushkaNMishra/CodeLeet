class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(); //row
        int m=grid[0].size(); //col
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i+1<n && grid[i+1][j]==1){ //if down neighbour is present
                        ans--;
                    }
                    if(i-1>=0 && grid[i-1][j]==1){ //if up neighbour is present
                        ans--;
                    }
                    if(j-1>=0 && grid[i][j-1]==1){ //if left neighbour is present
                        ans--;
                    }
                    if(j+1<m && grid[i][j+1]==1){ //if right neighbour is present
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};