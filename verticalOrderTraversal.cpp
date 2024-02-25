// Try to solve with Inorder, preorder 

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push( {root, {0, 0}} );
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int v = p.second.first;
            int l = p.second.second;
            nodes[v][l].insert(node->val);
            if(node->left) {
                q.push({node->left, {v-1, l+1}});
            }
            if(node->right) {
                q.push({node->right, {v+1, l+1}});
            }
        }
        
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
