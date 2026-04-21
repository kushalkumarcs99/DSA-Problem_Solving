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
    unordered_map<int, vector<int>> graph;

    void buildGraph(TreeNode* node, TreeNode* parent) {
        if(!node) return;

        if(parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    int BFS(int start) {
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int time = -1; // IMPORTANT

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int curr = q.front();
                q.pop();

                for(auto neigh : graph[curr]) {
                    if(!visited.count(neigh)) {
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }

            time++; // level completed
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root, nullptr);
        return BFS(start);
    }
};