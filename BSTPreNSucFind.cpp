// Try with recursion and in single func

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = NULL;
        suc = NULL;
        
        findPre(root, pre, key);
        findSuc(root, suc, key);
    }
    
    void findPre(Node* root, Node*& pre, int key) {
        while(root) {
            if(root->key >= key) {
                root = root->left;
            }
            else {
                pre = root;
                root = root->right;
            }
        }
    }
    
    void findSuc(Node* root, Node*& suc, int key) {
        while(root) {
            if(root->key <= key) {
                root = root->right;
            }
            else {
                suc = root;
                root = root->left;
            }
        }
    }
};
