class Solution {
public:
    int strLen;
    int wdLen;
    int wdSz;
    int windowSz;
    unordered_map<string, int> wordCounts;
    vector<int> result;

    void setMap(unordered_map<string, int>& wordsMap,const vector<string>& words){
        std::for_each(words.begin(), words.end(),[&wordsMap](string word){
            wordsMap[word]++;
        });
    }

    void movingWindow(int start, int end, string s, const vector<string> &words) {
        while (end <= strLen) {
            unordered_map<string, int> found;

            int w = 0;
            for (; w < wdSz; w++) {
                int wdStartPos = start + w * wdLen;
                string word = s.substr(wdStartPos, wdLen);

                if(wordCounts.find(word)==wordCounts.end()){
                    start = wdStartPos + wdLen;
                    end = start + windowSz;
                    break;
                }
                else {
                    if(++found[word] > wordCounts[word]) {
                        start += wdLen;
                        end += wdLen;
                        break;
                    }
                }
            }

            if(w==wdSz) {
                result.push_back(start);
                start += wdLen;
                end += wdLen;
            }
        }
    }

    vector<int> findSubstring(string s, vector<string> &words) {
        strLen = s.length();
        wdLen = words.front().length();
        wdSz = words.size();
        windowSz = wdLen * wdSz;
        setMap(wordCounts, words);

        for (int i = 0; i < wdLen; i++) {
            int start = i;
            int end = start + windowSz;

            //윈도우를 움직여가면서 찾기
            movingWindow(start, end, s, words);
        }

        return result;
    }
};