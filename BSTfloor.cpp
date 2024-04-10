class Solution{

public:
    int floor(Node* root, int x) {
        int flor = -1;
        
        while(root) {
            if(root->data == x) {
                flor = root->data;
                return flor;
            }
            else if(root->data < x) {
                flor = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return flor;
    }
};
