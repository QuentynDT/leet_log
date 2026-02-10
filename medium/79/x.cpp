#include "../../timer.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size(), sz = word.size();
        auto dfs = [&](this auto self, int p, int i, int j) -> bool {
            if(i < 0 || i >= m || j < 0 || j >= n) return false;
            if(p == sz) return true;
            char c = board[i][j];
            if(c != word[p]) return false;
            board[i][j] = '#';
            bool x = self(p + 1, i + 1, j) || self(p + 1, i - 1, j) || self(p + 1, i, j + 1) || self(p + 1, i, j - 1);
            board[i][j] = c;
            return x;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};

struct token {
    vector<vector<char>> board;
    string word;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.exist(data.board, data.word);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED", true};
    tokens[1] = {{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "SEE", true};
    tokens[2] = {{{'A'}}, "AB", false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}