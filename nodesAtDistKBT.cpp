class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;  // node -> parent
        markParents(root, parents);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();

            if(level == k) {
                break;
            }
            level++;

            for(int i=0;i<size;i++) {
                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if(parents[current] && !visited[parents[current]]) {
                    visited[parents[current]] = true;
                    q.push(parents[current]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
