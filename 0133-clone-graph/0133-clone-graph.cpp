/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
        {
            return node;
        }

        unordered_map<Node*, Node*> visited;

        deque<Node*> queue{node};

        visited[node] = new Node(node->val, {});

        while(!queue.empty())
        {
            Node* n = queue.front();
            queue.pop_front();

            for(Node* neighbor : n->neighbors)
            {
                if(visited.find(neighbor) == visited.end())
                {
                    visited[neighbor] = new Node(neighbor->val, {});
                    queue.push_back(neighbor);
                }

                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};