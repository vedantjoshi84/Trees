class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        vector<int> temp;
        pathFinder(root, ans, temp);
        return ans;
    }
    
    void pathFinder(Node* node, vector<vector<int>> &ans, vector<int> temp) {
        if(node == NULL) {
            return;
        }
        temp.push_back(node->data);
        if(node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
            return;
        }
        
        pathFinder(node->left, ans, temp);
        pathFinder(node->right, ans, temp);
    }
};
