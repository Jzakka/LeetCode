
class Solution {
public:
    map<int, set<string>> DPContainer;

    vector<string> generateParenthesis(int n) {
        DPContainer[1] = set<string>{"()"};

        if (n == 1) {
            return vector<string>(1, "()");
        } else {
            for (int i = 2; i <= n; i++) {
                set<string> &prevSet = DPContainer[i - 1];

                for (int j = 1; j < i; j++) {
                    set<string> &jSet = DPContainer[j];
                    set<string> &remainSet = DPContainer[i - j];

                    for (auto &je: jSet) {
                        for (auto &remaine: remainSet) {
                            DPContainer[i].insert(je + remaine);
                        }
                        if(j==i-1)
                            DPContainer[i].insert("(" + je + ")");
                    }
                }
                
                /*
                
                for (auto &e: prevSet) {
                    string wrap = "(" + e + ")";
                    DPContainer[i].insert(wrap);

                    string right = e + "()";
                    DPContainer[i].insert(right);

                    string left = "()" + e;
                    DPContainer[i].insert(left);
                }*/
            }
        }

        vector<string> result;
        set<string> &resultSet = DPContainer[n];
        std::for_each(resultSet.begin(), resultSet.end(), [&result](string str) {
            result.push_back(str);
        });

        return result;
    }
};