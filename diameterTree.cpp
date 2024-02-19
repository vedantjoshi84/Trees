class Solution {
private:
    int height(TreeNode* root, int &maxi) {
        if(root == NULL) {
            return 0;
        }
        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);
        maxi = max(lh+rh, maxi);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
