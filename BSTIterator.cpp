class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
