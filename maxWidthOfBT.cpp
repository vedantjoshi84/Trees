class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        // Imp to take long long to avoid overflow
        unsigned long long int ans = 0;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            unsigned long long int size = q.size();
            unsigned long long int mmin = q.front().second;
            unsigned long long int first, last;
            for(int i=0; i < size; i++) {
                unsigned long long int curr_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) {
                    first = curr_id;
                }
                if(i == size-1) {
                    last = curr_id;
                }

                if(node->left) {
                    q.push({node->left, 2*curr_id+1});
                }
                if(node->right) {
                    q.push({node->right, 2*curr_id+2});
                }
            }
            ans = max(ans, last - first +1);
        }
        return ans;
    }
};
