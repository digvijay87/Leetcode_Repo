class Solution {
    //vector<int, vector<pair<int,int>>> g;
    //queue <
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid.size();
        
        if(r == 0)
            return -1;
        if(c == 0)
            return -1;
        if(grid[0][0] != 0 || grid[r-1][c-1] != 0)
            return -1;
        
        queue<pair<int,int>> q;
        
        vector<pair<int,int>> dir = { {1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {-1,1}, {1,-1} };
        
        grid[0][0] = 1;
        
        q.push(make_pair(0,0));
        
        while(!q.empty())
        {
            auto cur = q.front();
            int x = cur.first;
            int y = cur.second;
            
            if(x == r-1 && y == c-1)
                return grid[x][y];
            
            for(auto d : dir){
                int nx = x+d.first;
                int ny = y+d.second;
                
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0)
                {
                    grid[nx][ny] = 1 + grid[x][y];
                    q.push({nx,ny});
                }
            }
            q.pop();
        }
        return -1;
        
    }
};
