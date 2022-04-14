class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        int count = -1;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int k = 0; k < n; k++)
            {
                auto cur = q.front();
                int x = cur.first;
                int y = cur.second;
                
                q.pop();
                
                for(auto d : dir)
                {
                    int nx = d.first + x;
                    int ny = d.second + y;
                
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
                
            }
            count +=1;
        }
        if(fresh>0) return -1; 
        if(count ==-1) return 0; 
        return count;
    }
};
