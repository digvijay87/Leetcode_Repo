
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        
        if(root == NULL)
            return ret;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            ret.emplace_back();
            
            for(int i = q.size(); i >= 1; i--)
            {
                Node* cur = q.front();
                q.pop();
                ret.back().push_back(cur->val);
                for (Node* child : cur->children) {
                    q.push(child);
                }
            }
        }    
        return ret;
    }
};
