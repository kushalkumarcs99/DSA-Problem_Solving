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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // value -> index in inorder
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, (int)postorder.size() - 1,
                         inorder, 0, (int)inorder.size() - 1,
                         inMap);
    }

private:
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inMap)
    {
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        // Root is last element in the current postorder range
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];        // index of root in inorder
        int numsLeft = inRoot - inStart;    // size of left subtree

        // Left subtree
        root->left = buildTree(postorder,
                               postStart,
                               postStart + numsLeft - 1,
                               inorder,
                               inStart,
                               inRoot - 1,
                               inMap);

        // Right subtree
        root->right = buildTree(postorder,
                                postStart + numsLeft,
                                postEnd - 1,
                                inorder,
                                inRoot + 1,
                                inEnd,
                                inMap);

        return root;
    }
};
