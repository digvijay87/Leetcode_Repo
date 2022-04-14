class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            Node *right = NULL;
            for(int i = n; i ; i--)
            {
                Node *temp = q.front();
                q.pop();
                temp->next = right;
                right = temp;
                if(temp->right){
                    q.push(temp->right);
                    q.push(temp->left);
                }
                
                
            }
        }
      return root;  
    }
};
