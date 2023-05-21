class Solution {
void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, queue<pair<int,int>>&q)
{
if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || vis[i][j]==1 || grid[i][j]==0)
return;
vis[i][j]=1;
q.push({i,j});
dfs(i-1,j,grid,vis,q);
dfs(i,j+1,grid,vis,q);
dfs(i+1,j,grid,vis,q);
dfs(i,j-1,grid,vis,q);
}
public:
int shortestBridge(vector<vector<int>>& grid) {
int n=grid.size();
vector<vector<int>> vis(n,vector<int>(n,0));
queue<pair<int,int>>q;
int f=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(grid[i][j]==1)
{
if(f==0)
{
f++;
dfs(i,j,grid,vis,q);
}
else