void inorder(node) {
    if(node == NULL) {
        return;
    }

    inorder(node->left);
    cout<<node->data<<endl;
    inorder(node->right);
}