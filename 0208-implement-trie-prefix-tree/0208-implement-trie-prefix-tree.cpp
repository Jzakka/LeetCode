class Trie {
private:
    struct Node{
        vector<Node*> next = vector<Node*>(26, NULL);
    };
    set<string> wordSet;
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        wordSet.insert(word);
        auto node = root;
        for(auto &character:word ){
            if(!node->next.at(character-'a')){
                node->next.at(character - 'a') = new Node;
            }
            node = node->next.at(character - 'a');
        }
    }

    bool search(string word) {
        return wordSet.find(word) != wordSet.end();
    }

    bool startsWith(string prefix) {
        auto node = root;
        for(auto &character: prefix){
            if(!node->next.at(character-'a')){
                return false;
            }
            node = node->next.at(character - 'a');
        }
        return true;
    }
};