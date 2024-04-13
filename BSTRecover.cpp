class Solution {
private: 
    TreeNode *first, *prev, *middle, *last;

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);
        if(first && last) {
            swap(first->val, last->val);
        }
        else if(first && middle) {
            swap(first->val, middle->val);
        }
    }

    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        inorder(root->left);

        if( prev!=NULL && (prev->val > root->val) ) {
            // first violation (if written in array, they come adjacent)
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            // second violation (if written in array, they are not adjacent)
            else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }
};
