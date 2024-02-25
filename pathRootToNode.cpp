bool getPath(TreeNode* node, int value, vector<int> &arr) {
    if(node == NULL) {
        return false;
    }
    arr.push_back(node->val);
    
    if(value == node->val) {
        return true;
    }
    
    if(getPath(node->left, value, arr) || getPath(node->right, value, arr)) {
        return true;
    }
    
    arr.pop_back();
    return false;
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    getPath(A, B, arr);
    return arr;
}
