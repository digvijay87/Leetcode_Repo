/*class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
    }
};*/

/*
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
*/

class Solution {
public:
    vector<int> root;
    
    int find(int x)
    {
        if(x == root[x]) return root[x];
        return root[x] = find(root[x]);
    }
        
    void join(int x, int y){
        int i = find(x);
        int j = find(y);
        root[j] = root[i];
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        root.resize(n);
        unordered_map<int,vector<int>> m;
        
        for(int i = 0; i < n ; i++)
        {
            root[i] = i;
            
        }
        
        
        for(int i = 0; i < pairs.size(); i++)
        {
            join(pairs[i][0], pairs[i][1]);
            
        }
        /*for(int i = 0; s.size(); i++)
        {
            
        }*/
        
        
        for(int i=0;i<s.size();i++){
             //To Find the parent of each idx paired together
            //Input: s = "cba", pairs = [[0,1],[1,2]]
            m[find(i)].push_back(i);                     // This find is union find not STL find
        }
        for(auto v:m){
            string t;
            for(int i=0;i<v.second.size();i++)
                t+=s[v.second[i]];    //db
            
            //cout << t << endl;
            sort(t.begin(),t.end());  //bd
            for(int i=0;i<v.second.size();i++)
                s[v.second[i]]=t[i];
        }
        return s;
    }
};
