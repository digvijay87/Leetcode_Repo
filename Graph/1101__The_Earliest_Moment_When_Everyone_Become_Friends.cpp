class Solution {
    vector<int> rank;
    vector<int> root;
public:
    int find(int x)
    {
        if(x == root[x]) return root[x];
        
        return root[x] = find(root[x]);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int count = n;
        rank.resize(n);
        root.resize(n);
        for(int i = 0 ; i < n; i++)
        {
            rank[i] = 1;
            root[i] = i;
        }
        //printf("hello");
        sort(logs.begin(), logs.end());
        //printf("%d\n",logs[0][0]);
        for(int i = 0; i < logs.size(); i++)
        {
            int X = find(logs[i][1]);
            int Y = find(logs[i][2]);

            if(X != Y)
            {
                   if(rank[X] > rank[Y])
                    {
                        root[Y] = root[X];
                    }else if(rank[Y] > rank[X])
                    {
                        root[X] = root[Y];
                    }else{
                        root[Y] = root[X];
                        rank[X] +=1;
                    }
                    count--;
                    if(count == 1)
                        return logs[i][0];
                
            }
        }
        return -1;
    }
};
