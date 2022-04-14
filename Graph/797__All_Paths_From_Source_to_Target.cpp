class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int node, vector<vector<int>> &ans, vector<int> &path)
    {
        path.push_back(node);
        if(node == graph.size() - 1)
        {
            ans.emplace_back(path);
            return;
        }
        
        //vector<int> nextNode = graph[node];
       // auto &nextNode = graph[node];
        for(auto next : graph[node])
        {
            dfs(graph, next, ans, path);
            path.pop_back();                            // Clean up
            
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        if(graph.size() == 0)
            return ans;
        
        dfs(graph, 0, ans, path);
        
        return ans;
        
    }
};
