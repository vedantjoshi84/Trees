class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root, long minval, long maxval) {
        if(root == NULL) {
            return true;
        }
        if(root->val >= maxval || root->val <= minval) {
            return false;
        }
        return isValid(root->left, minval, root->val) && isValid(root->right, root->val, maxval);
    }
};
