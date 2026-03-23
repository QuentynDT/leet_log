#include "../../timer.h"

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        static constexpr int kMod = 1'000'000'007;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2)));
        dp[0][0][0] = grid[0][0], dp[0][0][1] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0][0] = grid[i][0] * dp[i - 1][0][0];
            dp[i][0][1] = grid[i][0] * dp[i - 1][0][1];
        }
        for(int j = 1; j < n; j++){
            dp[0][j][0] = grid[0][j] * dp[0][j - 1][0];
            dp[0][j][1] = grid[0][j] * dp[0][j - 1][1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(grid[i][j] == 0){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                } else if(grid[i][j] > 0){
                    dp[i][j][0] = max(grid[i][j] * dp[i][j - 1][0], grid[i][j] * dp[i - 1][j][0]);
                    dp[i][j][1] = min(grid[i][j] * dp[i][j - 1][1], grid[i][j] * dp[i - 1][j][1]);
                } else {
                    dp[i][j][0] = max(grid[i][j] * dp[i][j - 1][1], grid[i][j] * dp[i - 1][j][1]);
                    dp[i][j][1] = min(grid[i][j] * dp[i][j - 1][0], grid[i][j] * dp[i - 1][j][0]);
                }
            }
        }
        return dp[m - 1][n - 1][0] >= 0 ? dp[m - 1][n - 1][0] % kMod : -1;
    }
};

struct token {
    vector<vector<int>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxProductPath(data.grid);
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
    vector<token> tokens;
    tokens.push_back({{{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}}, -1});
    tokens.push_back({{{1,-2,1},{1,-2,1},{3,-4,1}}, 8});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}