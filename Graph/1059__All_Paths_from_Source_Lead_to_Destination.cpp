class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &graph, vector<bool> &vis, int source, int dest )
    {
        if (graph[source].empty()){
            if (source == dest) {
                return true;
            };
            printf("empty\n");
        return false;
        }
        
         vis[source] = true;
        
        for (auto next: graph[source]){
            if(vis[next] || !dfs(graph, vis, next, dest))
                return false;
            
            vis[next] = false;  // back track
        }
        
        return true;    
    
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> vis(n);
        
        return dfs(graph, vis, source, destination);
    }
};
