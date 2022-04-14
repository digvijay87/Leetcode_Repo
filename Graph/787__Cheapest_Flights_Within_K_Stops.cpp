class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src == dst)
            return 0;
        
        vector<int> prev(n,INT_MAX);
        vector<int> cur(n,INT_MAX);
        
        prev[src] = 0;
        //k = 1 that mean we have no stopage or only 1 edge 
        // pre 0 # #
        // cur 0 100 500
        
        
        for(int i = 1; i < k+2; i++)
        {
            cur[src] = 0;
            
            for(auto &flight : flights)
            {
                int prev_flight = flight[0];
                int cur_flight = flight[1];
                int cost = flight[2];
                
                if(prev[prev_flight] < INT_MAX)
                {
                    cur[cur_flight] = min(prev[prev_flight] + cost, cur[cur_flight]);
                }
                
            }
            prev.assign(cur.begin(), cur.end());
        }
        
        return cur[dst] == INT_MAX ? -1 : cur[dst];
    }
};
