class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int hl = maxDepth(root->left);
        int hr = maxDepth(root->right);
        return 1+max(hl, hr);
    }
};
