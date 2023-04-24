class Solution {
public:
    string simplifyPath(string path) {
        string delim = "/";
        vector<string> files;

        size_t pos = 0;
        while ((pos = path.find(delim)) != string::npos) {
            files.push_back(path.substr(0, pos));
            path.erase(0, pos + 1);
        }
        if (pos == string::npos) {
            files.push_back(path);
        }
        string res = "";
        vector<string> canon;
        for (auto &f: files) {
            if (f == "..") {
                if (!canon.empty())
                    canon.pop_back();
            } else if (f == "" || f == ".") {
                continue;
            } else {
                canon.push_back(f);
            }
        }
        for (auto &c: canon) {
            res += "/" + c;
        }
        return res == "" ? "/" : res;
    }
};