class Solution {
public:

// 1. Recursion
//  TreeNode * prev = NULL ;
//     void flatten(TreeNode* root) {
        
//         if(root ==  NULL) return ;

//         flatten(root->right);
//         flatten(root->left); 

//         root->right = prev; 
//         root->left = NULL ; 
 
//         prev = root;
//     }

// 2. Using stack
    // void flatten(TreeNode* root) {
    //     if(!root) return;
    //     stack<TreeNode*> s; 
    //     s.push(root); 
        
    //     while(!s.empty()) {
    //         TreeNode *curr = s.top(); 
    //         s.pop(); 

    //         if(curr->right!= NULL) {
    //             s.push(curr->right);
    //         }
    //         if(curr->left!= NULL) {
    //             s.push(curr->left);
    //         }

    //         if(!s.empty()) {
    //             curr->right = s.top(); 
    //         }
    //         curr->left = NULL; 
    //     }
    // }

    // 3. Using threads
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != NULL) {
            if(cur->left != NULL) {
                TreeNode* prev = cur->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = cur->right;
                
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
