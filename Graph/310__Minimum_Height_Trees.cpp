
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       if(n==0)
            return {};
        if(n==1)
            return {0};
    
        vector<int>res;
        vector<int>degree(n,0);
        vector<vector<int>>g(n);
     
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            g[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;//updating how many edges each node has
            degree[edges[i][0]]++;
        }
    
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)//adding all the leave nodes
                q.push(i);
        }
     
        while(!q.empty())
        {
            res.clear();// clear vector before we start traversing level by level.
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int cur=q.front();
                q.pop();
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for(auto &nbr:g[cur])
                {
                    degree[nbr]--;//removing current leave nodes
                    if(degree[nbr]==1)//adding current leave nodes
                        q.push(nbr);
                }
            }
        }
        
        return res;
        
    }
};
