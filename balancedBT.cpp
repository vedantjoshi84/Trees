class Solution {
public:
    int height(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) {
            return true;
        }
        if( abs(height(root->left) - height(root->right)) <= 1 ) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else {
            return false;
        }
    }
};
