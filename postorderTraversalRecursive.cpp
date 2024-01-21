void inorder(node) {
    if(node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<endl;
}