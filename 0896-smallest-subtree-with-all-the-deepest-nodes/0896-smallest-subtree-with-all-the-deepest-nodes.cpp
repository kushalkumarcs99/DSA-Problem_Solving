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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode* node)
    {
        if(!node) return {0, nullptr};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int leftdepth = left.first;
        int rightdepth = right.first;
        TreeNode* leftnode = left.second;
        TreeNode* rightnode = right.second;

        if(leftdepth == rightdepth)
        {
            return {leftdepth+1, node};
        }
        else if(leftdepth > rightdepth)
        {
            return {leftdepth+1, leftnode};
        }
        else
        {
            return {rightdepth + 1, rightnode};
        }
    }
};