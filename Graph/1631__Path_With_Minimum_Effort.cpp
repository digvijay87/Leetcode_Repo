class Solution {
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    class cell{
    public:
        int x, y;
        int diff;
        cell(int x,int y, int diff){
            this->x = x;
            this->y = y;
            this->diff = dig
        }
        
            
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));  // mxn
        dp[0][0] = 0;
        
        priority_queue<int000000000000
        
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; i < n; j++)
            {
                for(auto &d : dir)
                {
                    int r = i+d.first;
                    int c = j+d.second;
                    
                    if(r >= 0 && c >=0 && r < n && c < m)
                    {
                        dp[r][c] = abs(heights[i][j] - heights[r][c]);
                        ans = min(ans, dp[r][c]);
                    }
                }
            }
        }
        return ans;
    }
};
