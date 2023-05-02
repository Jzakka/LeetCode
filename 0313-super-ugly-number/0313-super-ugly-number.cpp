class Solution {
public:
    struct Candidate {
        unsigned long long exponential;
        unsigned long long content;
        int idx;

    public:
        Candidate(int exponential) : exponential(exponential), content(exponential), idx(0) {}

        bool operator<(const Candidate& operand) const {
            return this->content < operand.content;
        }
    };

    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<Candidate> candidates;
        for (const auto &prime: primes) {
            candidates.push_back(Candidate(prime));
        }

        vector<unsigned long long> DP;
        DP.push_back(1);
        for (int i = 0; i < n; i++) {
            auto nextNum = std::min_element(candidates.begin(), candidates.end())->content;

            DP.push_back(nextNum);
            for (auto &candidate: candidates){
                if (candidate.content == nextNum) {
                    candidate.idx++;
                    candidate.content = DP.at(candidate.idx) * candidate.exponential;
                }
            }
        }

        return DP.at(n - 1);
    }
};