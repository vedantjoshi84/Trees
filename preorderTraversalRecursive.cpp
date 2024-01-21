void preorder(node) {
    if(node == NULL) {
        return;
    }

    cout<<node->data<<endl;
    preorder(node->left);
    preorder(node->right);
}

// TC O(N)
// SC Auxiliary space of height of tree - worst case skew tree O(N)