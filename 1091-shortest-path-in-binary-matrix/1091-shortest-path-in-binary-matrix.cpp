// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
//     }
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<int>q;
        int i=0,r=0,c=0,n=grid.size(),s=0,d=1,b=0;
        vector<int>a(n*n,-1),f(n*n,-1);
        q.push(0);
        while(q.size()>0)
        {
            s=q.size();
            for(i=0;i<s;i++)
            {
                b=q.front();
                if(f[b]!=-1) 
                {
                    q.pop();
                    continue;
                }
                r=b/n,c=b%n;
                if(grid[r][c]==1) 
                {
                    q.pop();
                    continue;
                }
                a[b]=d,f[b]=0;
                if(r>0)
                {
                    q.push(b-n);
                    if(c>0) q.push(b-n-1);
                    if(c<n-1) q.push(b-n+1);
                }
                if(c>0) q.push(b-1);
                if(c<n-1) q.push(b+1);
                if(r<n-1)
                {
                    q.push(b+n);
                    if(c>0) q.push(b+n-1);
                    if(c<n-1) q.push(b+n+1);
                }
                q.pop();
            }
            d++;
        }
        return a[a.size()-1];
    }
};