// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
        
//     }
// };

class Solution {
public:
    //graph coloring

    //flag variable, to be turned on when an error of two neighbouring nodes having same colour is detected
    bool flag = false;

    //dfs traversal
    void dfs(int ind, vector<vector<int>>& graph, vector<int>& color, int currcolor)
    {

        //color the current node
        color[ind]=currcolor;


        for(auto it: graph[ind])
        {

            //if a neighbour node is not coloured yet then color it with opposite color 
            if(color[it] == 0) dfs(it, graph, color, currcolor*(-1));

            //if a neighbour node is already coloured then it should have opposite colour what current node is having right now
            //else if a neighbour have same colour then making this graph a bipartite is not possible
            else if(color[it] == currcolor)
            {
                flag=true;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        //no of nodes in graph
        int n = graph.size();
        
        //coloring array
        vector<int> color(n, 0);

        for(int i=0; i<graph.size(); i++)
        {
            //if a uncolored node in encountered then color it and it's corresponding uncoloured neighbouring node
            if(color[i]==0) dfs(i, graph, color, 1);

            //if flag got turned on then making this graph bipartite is not possible
            if(flag) return false;
        }

        return true;
    }
};