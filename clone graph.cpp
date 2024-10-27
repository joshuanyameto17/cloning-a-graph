#include <unordered_map>
#include <vector>
using namespace std;

// Forward declaration of the Node class to use it in the Solution.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, std::vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    // A dictionary to keep track of all visited nodes and their clones.
    std::unordered_map<Node*, Node*> visited;

    // Function to clone a graph.
    Node* cloneGraph(Node* node) {
        // If the input node is null, return null indicating no node to clone.
        if (!node) return nullptr;

        // If the node has been already visited, return the clone from visited.
        if (visited.find(node) != visited.end()) return visited[node];

        // Create a new node with the same value as the input node.
        Node* cloneNode = new Node(node->val);
        // Record the visited node by mapping the original node to the clone.
        visited[node] = cloneNode;

        // Iterate over all neighbors of the input node.
        for (auto& neighbor : node->neighbors) {
            // Recursively call cloneGraph for each neighbor and add it to the cloned node's neighbors.
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        // Return the cloned node.
        return cloneNode;
    }
};
