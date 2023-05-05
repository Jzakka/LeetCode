class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        unordered_set<int> visited;

        queue<int> Q;
        Q.push(amount);

        int level = 0;
        while (!Q.empty()) {
            int qLen = Q.size();

            for (int i = 0; i < qLen; i++) {
                int remain = Q.front();
                Q.pop();
//                cout << remain << ", ";

                for (const auto &coin: coins) {
                    int diff = remain - coin;
                    if (visited.find(diff) == visited.end()){
                        if (diff == 0) {
                            return level+1;
                        } else if (diff > 0) {
                            Q.push(diff);
                            visited.insert(diff);
                        }
                    }
                }
            }
//            cout << "\n";
            level++;
        }

        return -1;
    }

};