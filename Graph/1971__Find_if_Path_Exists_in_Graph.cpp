class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    
    bool dfs(int cur, int end)
    {
        if(cur == end)
            return true;
        if(vis[cur] == true)
            return false;
        vis[cur] = true;
    // DFS Starts here    
        for(int next : graph[cur])
        {
            if(dfs(next, end))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        graph.resize(n), vis.resize(n);
        
        for(auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(start, end);
    }
};
