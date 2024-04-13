class Solution {
public:
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        smallest(root, k);
        return ans;
    }

    void smallest(TreeNode* root, int& k) {
        if(root == NULL) {
            return;
        }
        smallest(root->left, k);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        smallest(root->right, k);
    }
};

// or iterative

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        while(true) {
            while(root!=NULL) {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            k--;
            if(k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};
