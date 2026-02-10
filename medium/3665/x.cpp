#include "../../timer.h"

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        constexpr int kMod = 1'000'000'007;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<pair<int, int>>> jump(m, vector<pair<int, int>>(n, {-1, -1}));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    int ni = i + 1;
                    int nj = j + 1;
                    if (ni < m && nj < n) {
                        if (grid[ni][nj] == 0) {
                            jump[i][j] = {ni, nj};
                        } else {
                            jump[i][j] = jump[ni][nj];
                        }
                    }
                }
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0 || grid[i][j] == 1) continue;
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % kMod;
                    } else {
                        pair<int, int> dest = jump[i][j + 1];
                        if (dest.first != -1) {
                            dp[dest.first][dest.second] = (dp[dest.first][dest.second] + dp[i][j]) % kMod;
                        }
                    }
                }
                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % kMod;
                    } else {
                        pair<int, int> dest = jump[i + 1][j];
                        if (dest.first != -1) {
                            dp[dest.first][dest.second] = (dp[dest.first][dest.second] + dp[i][j]) % kMod;
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

struct token {
    vector<vector<int>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.uniquePaths(data.grid);
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
    const int n = 1;
    vector<token> tokens(n);
    tokens[0] = {{{0,1,0},{0,0,1},{1,0,0}}, 5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}