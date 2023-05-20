class Solution {
public:
    
    
    void dfs(unordered_map<string, vector<pair<string,double>>>&adj, string src, string des, unordered_set<string>&visited, double product, double &ans){
        //&ans for reference
         
        if(visited.find(src)!=visited.end()){
            return;
        }
        visited.insert(src); //mark visited
        
        if(src==des){
            ans=product;
            return;
        }
        for(auto it: adj[src]){
            string v=it.first;
            double val=it.second;
            
            dfs(adj,v,des,visited,product*val,ans);
        }
    }
    
    //meta and amazon
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //graph traversal
        //adj list-> a/b => 
        //a->(b,2)
        //b->(a,1/2)
        //dfs & product=1, src and destn
        
        int n=equations.size();
        unordered_map<string, vector<pair<string,double>>>adj;
        
        //make graph(adj)
        for(int i=0;i<n;i++){
            string u=equations[i][0]; //"a"
            string v=equations[i][1]; //"b"
            
            double val=values[i]; // a/b or u/v
            
            adj[u].push_back({v,val});      //a/b
            adj[v].push_back({u,1.0/val});  //b/a 
            // here 1.0 will be converted as double
        }
        vector<double>res;
        for(auto &query : queries){
            string src=query[0];
            string des=query[1];
            double ans=-1.0;
            double product=1.0;
            
            if(adj.find(src)!=adj.end()){
                unordered_set<string>visited;
                dfs(adj,src,des,visited,product,ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};