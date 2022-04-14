class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
      //  printf("%d\n",count);
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
/*
class unionFind{
    private:
        vector<int> root;
        vector<int> rank;
        int count;
    public:
        unionFind(int s) : root(s), rank(s), count(s){
            for(int i = 0; i < s; i++){
                root[i] = i;
                rank[i] = 0;
            }
        }
    
        int find(int x)
        {
            if(x == root[x])
            {
                return x;
            }
            return root[x] = find(root[x]);
        }
    
        void unionset(int x, int y)
        {
            int root_x = find(x);
            int root_y = find(y);
            
            if(root_x != root_y)
            {
                if(rank[root_x] > rank[root_y])
                {
                    root[root_y] = root_x;
                }else if(rank[root_x] < rank[root_y])
                {
                    root[root_x] = root_y;
                }
                else{
                    root[root_y] = root_x;
                    rank[root_x] += 1; 
                }
            }
            count--;
        }
    
        int getCount()
        {
            return count;
        }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        if(sz == 0)
            return 0;
        unionFind uf(sz);
        
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                if(isConnected[i][j] == 1)
                    uf.unionset(i,j);
        }
        }
            
        return uf.getCount();
        
    }
};
*/
