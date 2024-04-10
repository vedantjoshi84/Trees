class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};

// or 

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        
        while(curr!=NULL) {
            if(curr->val == val) {
                return curr;
            }
            else if(curr->val > val) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return curr;
    }
}
