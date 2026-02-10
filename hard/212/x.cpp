#include "../../timer.h"

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string* word = nullptr;
};

class Solution {
private:
    void insert(TrieNode* root, string& key){
        TrieNode* curr = root;
        for(char& c : key){
            if(curr -> children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->word = &key;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            insert(root, w);
        }

        vector<string> result;
        const int m = board.size(), n = board[0].size();

        auto dfs = [&](this auto self, int r, int c, TrieNode* node) -> void {
            if(r < 0 || r >= m || c < 0 || c >= n) return;
            char ch = board[r][c];
            if (ch == '#' || !node->children[ch - 'a']) return;

            node = node->children[ch - 'a'];
            if (node->word) {
                result.push_back(*node->word);
                node->word = nullptr;
            }

            board[r][c] = '#';
            self(r - 1, c, node);
            self(r + 1, c, node);
            self(r, c - 1, node);
            self(r, c + 1, node);

            board[r][c] = ch;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root);
            }
        }

        return result;
    }
};

struct token {
    vector<vector<char>> board;
    vector<string> words;
    vector<string> ans;
    vector<string> res;
};

void handle(token& data){
    Solution s;
    data.res = s.findWords(data.board, data.words);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main(){
    const int n = 2;
    vector<token> tokens(n);
    tokens[0] = {{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}, {"oath","pea","eat","rain"}, {"eat","oath"}};
    tokens[1] = {{{'a','b'},{'c','d'}}, {"abcb"}, {}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}