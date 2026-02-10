#include "../../timer.h"

class Solution {
public:
    void d(vector<vector<vector<int>>>& dp){
        for(const vector<vector<int>>& m : dp){
            for(const vector<int>& v : m){
                for(const int& x : v){
                    cout << x << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int c;
        int st = (grid[0][0] > 0);
        c = st;
        dp[0][0][c] = grid[0][0];
        for(int i = 1; i < m; i++){
            if(grid[i][0] == 0){
                dp[i][0][c] = dp[i - 1][0][c];
            } else if(c == k){
                break;
            } else {
                dp[i][0][c + 1] = grid[i][0] + dp[i - 1][0][c];
                c++;
            }
        }
        c = st;
        for(int j = 1; j < n; j++){
            if(grid[0][j] == 0){
                dp[0][j][c] = dp[0][j - 1][c];
            } else if(c == k){
                break;
            } else {
                dp[0][j][c + 1] = grid[0][j] + dp[0][j - 1][c];
                c++;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int cost = (grid[i][j] > 0);
                for(int c = 0; c <= k; c++){
                    if(dp[i - 1][j][c] == -1 && dp[i][j - 1][c] == -1) continue;
                    if(cost == 1 && c == k) continue;
                    dp[i][j][c + cost] = grid[i][j] + max(dp[i - 1][j][c], dp[i][j - 1][c]);
                }
            }
        }
        d(dp);
        return ranges::max(dp[m - 1][n - 1]);
    }
};

struct token {
    vector<vector<int>> grid;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxPathScore(data.grid, data.k);
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
    tokens[0] = {{{0, 1},{2, 0}}, 1, 2};
    tokens[1] = {{{0, 1}, {1, 2}}, 1, -1};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}