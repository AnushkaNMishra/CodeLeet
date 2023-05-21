class Solution {
    //microsoft
public:
    int m,n;
    
    vector<vector<int>>directions={
                {-1,0},
        {0,-1},            {0,1},
                {1,0}
    };
    
    
    bool isSafe(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int,int>>&visitedcell){
        if(!isSafe(i,j) || grid[i][j]==0 || visitedcell.find({i,j})!=visitedcell.end()){
                return;            
        }
        
        visitedcell.insert({i,j});
        
        for(auto &it: directions){
            int i_ = i + it[0];
            int j_ = j + it[1];
            
            dfs(grid,i_,j_,visitedcell);
        }
        
    }
    
    int bfs(vector<vector<int>>& grid, set<pair<int,int>>&visitedcell){
        queue<pair<int,int>>q;
        for(auto &it: visitedcell){
            q.push(it);  
        }
        int level=0;
        while(!q.empty()){
            int L=q.size();
            while(L--){
                pair<int,int>P=q.front();
                q.pop();
                
                int x=P.first;
                int y=P.second;
                
                for(auto &dir: directions){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    
                    if(isSafe(x_,y_) && visitedcell.find({x_,y_})==visitedcell.end()){
                        if(grid[x_][y_]==1){ //we found the 2nd island
                            return level;
                        }
                        visitedcell.insert({x_,y_});
                        q.push({x_,y_});
                    }
                }
            }
            level++;
        }
        return level;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        //multisource bfs
        m=grid.size(); //row
        n=grid[0].size(); //col
        
        set<pair<int,int>>visitedcell;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ //found 1st island
                    dfs(grid,i,j,visitedcell); //mark all  1 cell of first island and store them in visitedcell
                    return bfs(grid,visitedcell);
                }
            }
        }
        
        return -1; 
    }
};