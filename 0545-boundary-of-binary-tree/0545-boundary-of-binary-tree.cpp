/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* node) { return !node->left && !node->right; }

    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* current = root->left;
        while (current) {
            if (!isLeaf(current)) {
                res.push_back(current->val);
            }

            if (current->left) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* current = root->right;
        vector<int> tempResult;
        while (current) {
            if (!isLeaf(current)) {
                tempResult.push_back(current->val);
            }

            if (current->right) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        reverse(tempResult.begin(), tempResult.end());
        res.insert(res.end(), tempResult.begin(), tempResult.end());
    }

    void addLeaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }

        if (root->left) {
            addLeaves(root->left, res);
        }

        if (root->right) {
            addLeaves(root->right, res);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (isLeaf(root)) {
            res.push_back(root->val);
            return res;
        }
        res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};