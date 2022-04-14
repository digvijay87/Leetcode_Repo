class Solution {
    unordered_map<string, priority_queue< string, vector<string>, greater<string> >> g;
    
    void dfs(string s, vector<string> &path)
    {
        while(g[s].size() != 0)
        {
            string d = g[s].top();
            g[s].pop();
            
            dfs(d, path);
        }
        
        path.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        /*
        for(int i = 0 ; i < tickets.size(); i++)
        {
            g[tickets[i][0]].push(tickets[i][1]);
        }
        */
        for(auto &tck : tickets)
        {
            g[tck[0]].push(tck[1]);
        }
        vector<string> res;
        
        dfs("JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};
