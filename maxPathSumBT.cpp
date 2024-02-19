class Solution {
private:
    int height(TreeNode* root, int &maxi) {
        if(root==NULL) {
            return 0;
        }
        // For handling sums which are negative, return 0 instead
        int lsum = max(0, height(root->left, maxi));
        int rsum = max(0, height(root->right, maxi));

        maxi = max(maxi, lsum+rsum+root->val);
        return root->val + max(lsum, rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};
