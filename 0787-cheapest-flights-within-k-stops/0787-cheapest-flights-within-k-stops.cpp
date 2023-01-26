class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n]; 
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q; //stops,node,dist
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            int stop=i.first;
            int node=i.second.first;
            int distance=i.second.second;
            
            if(stop>k){
                continue;
            }
            
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edweight=it.second;
                
                    if(distance+edweight < dist[adjNode] && stop<=k){
                    dist[adjNode] = distance+edweight;
                    q.push({stop+1,{adjNode,distance+edweight}});
                }
            }
        }
        
        
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
        
         
    }
};
//stops will be taken into consideration rather than the weight