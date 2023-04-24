class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> versionNum1;
        vector<int> versionNum2;
        for (int i = 0; i < version1.length(); i++) {
            string revision = "";
            while (i < version1.length() && version1.at(i) != '.') {
                revision += version1.at(i);
                i++;
            }
            versionNum1.push_back(stoi(revision));
        }
        for (int i = 0; i < version2.length(); i++) {
            string revision = "";
            while (i < version2.length() && version2.at(i) != '.') {
                revision += version2.at(i);
                i++;
            }
            versionNum2.push_back(stoi(revision));
        }
        int n1 = versionNum1.size();
        int n2 = versionNum2.size();
        bool swaped = false;
        if (n1> n2) {
            swaped = true;
            swap(versionNum1, versionNum2);
        }
        for (int i = 0; i < abs(n1 - n2); i++) {
            versionNum1.push_back(0);
        }

        for (int i = 0; i < versionNum1.size(); i++) {
            if(versionNum1.at(i)>versionNum2.at(i)) {
                return swaped ? -1 : 1;
            } else if(versionNum1.at(i)<versionNum2.at(i)){
                return swaped ? 1 : -1;
            }
        }

        return 0;
    }
};