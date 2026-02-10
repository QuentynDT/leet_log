#include "../../timer.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto bfs = [&](int x, int y){
            queue<pair<int, int>> q{{{x, y}}};
            grid[x][y] = '2';
            while(!q.empty()){
                const auto [i, j] = q.front();
                q.pop();
                for(const auto& [dx, dy] : dirs){
                    x = i + dx;
                    y = j + dy;
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') continue;
                    q.emplace(x, y);
                    grid[x][y] = '2';
                }
            }
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};


struct token {
    vector<vector<char>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.numIslands(data.grid);
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
    tokens[0] = {{
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
}, 1};
    tokens[1] = {{
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
}, 3};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}