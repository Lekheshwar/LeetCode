
// QUESTION LINK : https://leetcode.com/problems/clone-graph/


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

    void dfs(Node* curr, Node* newNode, vector<Node *>& visited) {

        visited[newNode -> val] = newNode;

        for (auto elx : curr->neighbors) {

            if (visited[elx->val] == NULL) {
                Node* node = new Node(elx->val);
                (newNode -> neighbors).push_back(node);
                dfs(elx, node, visited);
            }

            else
                (newNode -> neighbors).push_back(visited[elx->val]);
        }
    }



    Node* cloneGraph(Node* node) {

        if (node == NULL) return NULL;

        vector<Node *> visited(101, NULL);
        Node* newRoot = new Node(node->val);

        visited[newRoot->val] = newRoot;

        for (auto curr : node->neighbors) {

            if (visited[curr->val] == NULL) {
                Node* newNode = new Node(curr->val);
                (newRoot -> neighbors).push_back(newNode);
                dfs(curr, newNode, visited);
            }

            else
                (newRoot->neighbors).push_back(visited[curr->val]);
        }
        return newRoot;
    }
};