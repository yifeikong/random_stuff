#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    char val;
    int count;
    TrieNode* firstChild;
    TrieNode* nextSibling;
};

void addNode(TrieNode* root, const string& word) {

    TrieNode* child = root->firstChild;

    for (int i = 0; i < word.size(); ++i) {
        while (child != NULL) {
            if (child->val == word[i])
                break;
            else
                child = child->nextSibling;
        }
        if (child != NULL) {
            child = child->firstChild;
            continue;
        }

        TrieNode* node = new TrieNode;
        node->val = word[i];
        node->count = 1;

};

void lookupPrefix(TrieNode* root, const string& word) {


};

int main() {

    // dumb root
    TrieNode* root = new TrieNode;
    root->val = 0;
    root->count = -1;
    root->firstChild = NULL;
    root->nextSibling = NULL;

    int dictSize;
    cin >> dictSize;
    for (int i = 0; i < dictSize; ++i) {
        string word;
        cin >> word;
        addNode(root, word);
    }

    int lookupSize;
    cin >> lookupSize;
    for (int i = 0; i < lookupSize; ++i) {
        string lookup;
        cin >> lookup;
        cout << lookupPrefix(root, lookup) << endl;
    }

    return 0;
}
