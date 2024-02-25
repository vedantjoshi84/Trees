class Solution
{
    public:
    
    //  Prefer doing this by level order and not recursive traversal as we 
    // will need to consider node with least height in a line. 
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int v = it.second;
            
            if(mp.find(v) == mp.end()) {
                mp[v] = node->data;
            }
            
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
