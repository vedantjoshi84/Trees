class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            if(reverse) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }

    public: 
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        bool hasNext() {
            return !st.empty();
        }

        int next() {
            TreeNode* tmp = st.top();
            st.pop();
            if(!reverse) {
                pushAll(tmp->right);
            }
            else {
                pushAll(tmp->left);
            }
            return tmp->val;
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j) {
            if(i+j == k) {
                return true;
            }
            else if(i+j < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};

// Using inorder and storing it, apply 2 sum
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> arr;
        inorder(root, arr);
        
        int i=0, j=arr.size()-1;
        while(i<j) {
            if(arr[i]+arr[j] == k) {
                return true;
            }
            else if(arr[i] + arr[j] < k) {
                i++;
            }
            else {
                j--;
            }
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int> &arr) {
        if(root==NULL) {
            return;
        }
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};

// Using set
class Solution {
public:
    set<int> s;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) {
            return false;
        }
        
        if(s.find(k - root->val) != s.end()) {
            return true;
        }
        
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
