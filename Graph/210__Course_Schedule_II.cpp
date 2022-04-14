class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        
        if(prerequisites.size() == 0)
        {
            for(int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
        }
        
        if(n == 0)
            return ans;
        
        vector<int> degree(n);
        
        unordered_map<int, vector<int>> um;
        
        for(int i = 0 ; i < prerequisites.size(); i++)
        {
            um[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        //[0 1]
        queue<int> q; 
        
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                int course = q.front();
                q.pop();
                ans.push_back(course);
                for(int j = 0; j < um[course].size(); j++)
                {
                    --degree[um[course][j]];
                    
                    if(degree[um[course][j]] == 0)
                        q.push(um[course][j]);
                }
                
                
            }
        }
        
        return n == ans.size() ? ans : vector<int>() ;
        //return ans;
        
    }
};
