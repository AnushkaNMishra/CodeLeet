class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find_ultPar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find_ultPar(parent[u]);
    }
    void Union(int u,int v){
        int ult_pu= find_ultPar(u);
        int ult_pv= find_ultPar(v);
        if(ult_pu==ult_pv){
            return ;
        }
        if(size[ult_pu]>size[ult_pv]){
            size[ult_pu]+=size[ult_pv];
            parent[ult_pv]=ult_pu;
        }
        else{
            size[ult_pv]+=size[ult_pu];
            parent[ult_pu]=ult_pv;
            
        }
    }
    int findSize(){
        // just return the size of any one cluster of nodes
        return size[find_ultPar(0)];
    }
};

class Solution {
public:
    // To find if one edge is critical, 
    //delete that edge('excluded') and re-run the MST algorithm 
    //and see if the weight of the new MST increases.
    bool check_critical(vector<int>&exclude, vector<vector<int>>& sorted_edges,int n,int mstWt){
        int weight=0;
        DSU ds(n);
        for(auto &it:sorted_edges){
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            if(u==exclude[0] && v==exclude[1] && wt==exclude[2]){
                cout<<"excluded : "<<u<<" "<<v<<" "<<wt<<endl;
                continue;
            }
            if(ds.find_ultPar(u)!=ds.find_ultPar(v)){
                weight+=wt;
                ds.Union(u,v);
            }
        }
        // cout<<"critical check mst weight : "<<weight<<endl;
        
        // return true if:
        //new MST wt is > mstWt 
        //or we can not make mst at all of N nodes
        return (weight>mstWt || ds.findSize()<n);
    }

    // To find if one edge is pseudo-critical (in any MST), 
    //include that edge (in the new MST) and continue the MST algorithm, 
    //then see if the resulting MST has the same weight of the initial MST of the entire graph.
    bool check_pseudoCritical(vector<int> &include,vector<vector<int>>& sorted_edges,int n,int mstWt){
        int weight=0;
        DSU ds(n);
        
        //including the edge explicitly 
        ds.Union(include[0],include[1]);
        weight+=include[2];
        
        // now simply running the Kruskal's Algorithm
        for(auto &it:sorted_edges){
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            if(ds.find_ultPar(u)!=ds.find_ultPar(v)){
                weight+=wt;
                ds.Union(u,v);
            }
        }

        // return true if on including this edge we can make mst of same wt 
        return weight==mstWt;
    }

    // Kruskal's Algorithm -- to find MST SUM
    int findMst(vector<vector<int>>& sorted_edges,int n){
        int weight=0;
        DSU ds(n);
        for(auto &it:sorted_edges){
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            if(ds.find_ultPar(u)!=ds.find_ultPar(v)){
                weight+=wt;
                ds.Union(u,v);
            }
        }
        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>sorted_edges;
        for(auto &it:edges){
            vector<int> curr_edge;
            curr_edge.push_back(it[2]);
            curr_edge.push_back(it[0]);
            curr_edge.push_back(it[1]);
            sorted_edges.push_back(curr_edge);
        }
        // sort the edges according to weight
        sort(sorted_edges.begin(),sorted_edges.end());
        int mstWt=findMst(sorted_edges,n);
        // cout<<"mstWt: "<<mstWt<<endl;

        vector<int> critical,pseudo_critical;

        // check each edge if it is critical or pseudo critical
        for(int i=0;i<edges.size();i++)
        {
            if(check_critical(edges[i],sorted_edges,n,mstWt)){
                critical.push_back(i);
            }
            else if(check_pseudoCritical(edges[i],sorted_edges,n,mstWt) ){
                pseudo_critical.push_back(i);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo_critical);
        
        return ans;
    }
};