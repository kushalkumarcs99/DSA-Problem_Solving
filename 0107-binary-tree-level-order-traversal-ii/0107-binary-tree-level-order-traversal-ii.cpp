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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> result;
    if (!root) return result; // If the tree is empty, return an empty result

    std::queue<TreeNode*> q;
    q.push(root); // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        std::vector<int> currentLevel;

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val); // Add the node's value to the current level

            // Add the left and right children to the queue for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel); // Add the current level to the result
    }
    reverse(result.begin(), result.end());
    return result;
    }
};