class Solution {
    unordered_map<Node* , Node*> map;
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        if(map.find(node) == map.end()){
            map[node] = new Node(node->val, {});
            
            for(Node* neighbor : node->neighbors)
                map[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return map[node];
        
        
    }
};
