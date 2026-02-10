#include "../../timer.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        const int m = board.size();
        const int n = board[0].size();
        auto dfs = [&](auto self, int i, int j) -> void {
            if(i < 0 || i >= m || j < 0 || j >= n) return;
            if(board[i][j] != 'O') return;
            board[i][j] = '*';  
            self(self, i + 1, j);
            self(self, i - 1, j);
            self(self, i, j + 1);
            self(self, i, j - 1);
        };
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i * j == 0 || i == m - 1 || j == n - 1){
                    dfs(dfs, i, j);
                }
            }
        }
        for (vector<char>& row : board){
            for (char& c : row){
                if (c == 'O') c = 'X';
                else if (c == '*') c = 'O';
            }
        }
    }
};

struct token {
    vector<vector<char>> board;
    vector<vector<char>> ans;
    vector<vector<char>> res;
};

void handle(token& data){
    Solution s;
    s.solve(data.board);
    data.res = data.board;
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
    tokens[0] = {{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}}, {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}}};
    tokens[1] = {{{'X'}}, {{'X'}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}