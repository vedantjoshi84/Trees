void preorder(Node* node, int level, vector<int> &ans) {
    if(node == NULL) {
        return;
    }

    if(ans.size() == level) {
        ans.push_back(node->data);
    }
    preorder(node->left, level+1, ans);
    preorder(node->right, level+1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    preorder(root, 0, ans);
    return ans;
}
