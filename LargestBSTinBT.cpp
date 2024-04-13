class NodeValue {
    public:
        int minNode, maxNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

class Solution{
    private:
        NodeValue largestBstHelper(Node *root) {
            if(!root) {
                return NodeValue(INT_MAX, INT_MIN, 0);
            }
            
            auto left = largestBstHelper(root->left);
            auto right = largestBstHelper(root->right);
            
            if(left.maxNode < root->data && root->data < right.minNode) {
                return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 
                                 left.maxSize+right.maxSize+1);
            }
            return NodeValue( INT_MIN, INT_MAX, max(left.maxSize, right.maxSize) );
        }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBstHelper(root).maxSize;
    }
};
