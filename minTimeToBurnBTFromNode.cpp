class Solution {
  private:
    Node* bfsToMapParents(Node* root, map<Node*, Node*> &parents, int target) {
        queue<Node*> q;
        q.push(root);
        Node* res;
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->data == target) {
                res = node;
            }
            
            if(node->left) {
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parents[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int findMaxDistance(map<Node*, Node*> parents, Node* target) {
        queue<Node*> q;
        map<Node*, bool> visited;
        q.push(target);
        visited[target] = true;
        int minT = 0;
        
        while(!q.empty()) {
            int flagB = 0;  // To check if any nodes burned or not in a iteration
            int size = q.size();
            
            for(int i=0;i<size;i++) {
                Node* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]) {
                    flagB = 1;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    flagB = 1;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parents[node] && !visited[parents[node]]) {
                    flagB = 1;
                    visited[parents[node]] = true;
                    q.push(parents[node]);
                }
            }
            if(flagB == 1) {
                minT++;
            }
        }
        return minT;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> parents;
        Node* targetV = bfsToMapParents(root, parents, target);
        int mint = findMaxDistance(parents, targetV);
        return mint;
    }
};
