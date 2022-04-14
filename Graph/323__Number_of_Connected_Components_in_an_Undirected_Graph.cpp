class unionfind{
    private:
        vector<int> rank;
        vector<int> root;
    public:
        
        unionfind(int n) : rank(n), root(n) {
            for(int i = 0; i < n; i++)
            {
                root[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x)
        {
            if(x == root[x]) return x;
             
            return root[x] = find(root[x]);
        }
    
        void unionset(int x, int y, int &count)
        {
            int root_x = find(x);
            int root_y = find(y);
            
            if(root_x != root_y)
            {
               if(rank[root_x] > rank[root_y])
               {
                   root[root_y] = root_x;
               }
               else if(rank[root_x] < rank[root_y])
               {
                   root[root_x] = root_y;
               }
               else
               {
                   root[root_y] = root_x;
                   rank[root_x] +=1;
               }
                count--;
               //return 1; 
            }//else{
               // return 0;
            //}
                
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unionfind uf(n);
        int count = n ;
        for(int i = 0; i < edges.size(); i++)
        {
            //count -= 
            uf.unionset(edges[i][0],edges[i][1],count);
            //if(uf.find(edges[i][0]) != uf.find(edges[i][1]))
        }
        return count;
    }
};
