class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        // Graph, adjenency list;
        vector<vector<pair<int,int>>> graph(n+1);
        
        //Min heap to extract minimum cost node
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        
        for(int i = 0; i < wells.size(); i++)
        {
            pair<int,int> pr = {wells[i], i+1}; // Indicates that at cost 1 st i+1 for example i = 0 (i+1)
            graph[0].push_back(pr);
            
            heap.push(pr);
        }
        
        // add all the esges to the graph
        
        for(int i = 0; i < pipes.size(); i++)
        {
            int house1 = pipes[i][0];
            int house2 = pipes[i][1];
            
            int cost = pipes[i][2];
            
            graph[house1].push_back({cost,house2});
            graph[house2].push_back({cost,house1});
            
            
        }
        // set for the visited 
        unordered_set<int> st = {0};
        
        int totalcost = 0;
        
        while(st.size() < n+1)
        {
            pair<int,int> edge = heap.top();
            
            heap.pop();
            
            int cost = edge.first;
            
            int nextHouse = edge.second;
            
            //If we have visited this house
            if(st.count(nextHouse))
                continue;
            
            st.insert(nextHouse);
            totalcost += cost;
            
            for(auto nbr : graph[nextHouse])
            {
                if(!st.count(nbr.second))
                    heap.push(nbr);
            }
            
        }
        return totalcost;
    }
};
