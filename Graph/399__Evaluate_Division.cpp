class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map <string, double>> graph;
        for (int i = 0; i < equations.size(); ++ i) {                   // build the graph
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> ret (queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++ i) {
            double path = 1.0;
            unordered_set <string> visited;
            find(graph, queries[i][0], queries[i][1], path, ret[i], visited);
        }
        return ret; 
    }
    
    void find (unordered_map<string,unordered_map<string,double>>& graph, string start, string end, double path, double& answer,
              unordered_set<string>& visited) {
        if (start == end) {
            if (graph.count(start)) answer = path;
            return;
        }
        visited.insert(start);
        for (auto &next : graph[start]) {
            if (!visited.count(next.first)) {   // not yet visited
                find(graph, next.first, end, path * next.second, answer, visited);
            }
        }
        
        return;
        
    }
};
