// Recursive will need additional logic for line and height, prefer this way

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector <int> ans;
        if(root==NULL) {
            return ans;
        }
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int v = it.second;
            
            mp[v] = node->data;
            
            if(node->left) {
                q.push({node->left, v-1});
            }
            if(node->right) {
                q.push({node->right, v+1});
            }
        }
        
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
