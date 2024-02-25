class Solution {
public:
    // can do level order but its space complexity will be higher
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        reversePreorder(root, 0, ans); 
        return ans;
    }

    void reversePreorder(TreeNode* node, int level, vector<int> &ans) {
        if(node == NULL) {
            return;
        }

        if(ans.size() == level) {
            ans.push_back(node->val);
        }
        reversePreorder(node->right, level+1, ans);
        reversePreorder(node->left, level+1, ans);
    }
};
