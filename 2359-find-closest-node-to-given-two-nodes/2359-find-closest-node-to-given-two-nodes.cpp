class Solution {
public:
   
    void dfs(vector<int>& edges, int node,vector<int>&dist, vector<bool>&visited){
        visited[node]=true;
        int val=edges[node];
        if(val!=-1 && !visited[val]){
            dist[val]=1+dist[node];
            dfs(edges,val,dist,visited);
        }   
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        
        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);
        
        dist1[node1]=0;
        dist2[node2]=0;
        
        dfs(edges,node1,dist1,visited1);
        dfs(edges,node2,dist2,visited2);
        
        int min_node=-1;
        int min_dist=INT_MAX;
        for(int i=0;i<n;i++){
            int path=max(dist1[i],dist2[i]);
            if(min_dist>path){
                min_dist=path;
                min_node=i;
            }
        }
        return min_node;
        
    }
};