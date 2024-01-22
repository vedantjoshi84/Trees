class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        if(root==NULL) {
            return inorder;
        }
        while(true) {
            if(root!=NULL) {
                st.push(root);
                root = root->left;
            }
            else {
                if(st.empty()) {
                    break;
                }
                root = st.top();
                st.pop();
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        return inorder;
    }
};