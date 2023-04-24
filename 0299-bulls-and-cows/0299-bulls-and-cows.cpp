class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_set<int> skip;
        int counts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        int bulls = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.at(i) == guess.at(i)) {
                bulls++;
                skip.insert(i);
            } else {
                counts[secret.at(i) - '0']++;
            }
        }

        int cows=0;
        for (int i = 0; i < guess.length(); i++) {
            if (skip.find(i) != skip.end()) {
                continue;
            }
            int digit = guess.at(i) - '0';
            if (counts[digit] > 0) {
                cows++;
                counts[digit]--;
            }
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};