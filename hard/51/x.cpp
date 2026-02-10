#include "../../timer.h"

class Solution {
public:
    void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,vector<bool>&& diag2, vector<string>&& board, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (cols[j] || diag1[i + j] || diag2[j - i + n - 1]) continue;
            board[i][j] = 'Q';
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
            dfs(n, i + 1, std::move(cols), std::move(diag1), std::move(diag2), std::move(board), ans);
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
            board[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        dfs(n, 0, vector<bool>(n), vector<bool>(2 * n - 1), vector<bool>(2 * n - 1), vector<string>(n, string(n, '.')), ans);
        return ans;
    }
};

struct token {
    int n;
    vector<vector<string>> ans;
    vector<vector<string>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.solveNQueens(data.n);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "Expected answer: ";
        display(t.ans);
        cout << '\n';
    }
}

int main(){
    const int n = 1;
    vector<token> tokens(n);
    tokens[0] = {4, {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}