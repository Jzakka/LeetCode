class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        vector<vector<bool>> edgeVisited (101, vector<bool>(101, false));
        vector<Node *> arr(101, nullptr);
        Node *root = new Node(node->val);
        arr[node->val] =  root;
        dupNode(root, node, edgeVisited, arr);
        return root;
    }

    void dupNode(Node *duplicated, Node *original, vector<vector<bool>> &edgeVisited, vector<Node *> &nodeArr) {
        cout << "\n"<< duplicated->val << ": ";
        for (auto &neighbor: original->neighbors) {
            cout << neighbor->val << "=";
            if (!edgeVisited[original->val][neighbor->val] && !edgeVisited[neighbor->val][original->val]) {
                cout << "O";
                edgeVisited[original->val][neighbor->val] = edgeVisited[neighbor->val][original->val] = true;
                Node *dupNeighbor;
                if (nodeArr[neighbor->val] == nullptr) {
                    dupNeighbor = new Node(neighbor->val);
                    nodeArr[neighbor->val] = dupNeighbor;
                } else {
                    dupNeighbor = nodeArr[neighbor->val];
                }

                duplicated->neighbors.emplace_back(dupNeighbor);
                dupNeighbor->neighbors.emplace_back(duplicated);
                dupNode(dupNeighbor, neighbor, edgeVisited, nodeArr);
            }
            cout << "\n";
        }
    }
};