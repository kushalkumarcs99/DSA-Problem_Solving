/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return Invert(root);
    }
    
    TreeNode* Invert (TreeNode* node)
    {
        if(node  == NULL) return NULL;
        
        if(node -> left == NULL && node -> right == NULL) return node;
        
        TreeNode* left = Invert(node -> left);
        TreeNode* right = Invert (node -> right);
        node -> right= left;
        node -> left = right;
        return node;
    }
};