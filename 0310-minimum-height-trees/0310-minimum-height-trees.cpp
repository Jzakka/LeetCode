class Solution {
private:
    queue<int> leaves;
    vector<unordered_set<int>> edges;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &inputEdges) {
        edges = vector<unordered_set<int>>(n);

        for (const auto &edge: inputEdges) {
            int src = edge.at(0);
            int dest = edge.at(1);

            edges.at(src).insert(dest);
            edges.at(dest).insert(src);
        }

        for (int i = 0; i < n; i++) {
            if (edges.at(i).size() == 1) {
                leaves.push(i);
            }
        }

        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            res.insert(i);
        }

        while (res.size()>2) {
            int qLen = leaves.size();

            for (int i = 0; i < qLen; i++) {
                int leaf = leaves.front();
                leaves.pop();
                res.erase(leaf);

                int parent = *edges.at(leaf).begin();
                edges.at(leaf).clear();
                edges.at(parent).erase(leaf);
                if (edges.at(parent).size() == 1) {
                    leaves.push(parent);
                }
            }
        }

        return {res.begin(), res.end()};
    }
};