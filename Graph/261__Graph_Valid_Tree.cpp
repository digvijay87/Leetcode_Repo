/* A valid tree if it has one singele root
Also if there is no circle 
*/

class unionFind {
    private :
        vector<int> root;
        vector<int> rank;
        
    public :
        unionFind(int s) : root(s), rank(s){
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
    
        void unionSet(int root_x, int root_y)
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
            
        }
    
    
    
    
        /*
        bool print()
        {
            int tocheck = root[0];
            for(int i = 0; i < root.size(); i++)
            {
                if(root[i] != tocheck){
                    return false;
                }
            }
            return true;
        }
        */
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1 != edges.size())
            return false;
        unionFind uf(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = uf.find(edges[i][0]);
            int y = uf.find(edges[i][1]);
            if(x==y)
                return false;
            
            uf.unionSet(x,y);
        } 
        return true;
       //return (n-1 == edges.size());
    }
};
