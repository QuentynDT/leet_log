#include "../../timer.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }
        for(int j = 1; j < n; j++){
            grid[0][j] += grid[0][j - 1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

struct token {
    vector<vector<int>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minPathSum(data.grid);
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
    tokens[0] = {{{1,3,1},{1,5,1},{4,2,1}}, 7};
    tokens[1] = {{{1,2,3},{4,5,6}}, 12};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}