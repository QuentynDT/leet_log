#include "../../timer.h"

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        const int sz = m * n;
        constexpr int kMod = 12345;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] %= kMod;
            }
        }
        vector<int> p(sz);
        vector<int> s(sz);
        p[0] = 1;
        for(int i = 0; i < sz - 1; i++){
            p[i + 1] = (grid[i / n][i % n] * p[i]) % kMod; 
        }
        s[sz - 1] = 1;
        for(int i = sz - 1; i > 0; i--){
            s[i - 1] = (grid[i / n][i % n] * s[i]) % kMod;  
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = (p[i * n + j] * s[i * n + j]) % kMod;
            }
        }
        return ans;
    }
};

struct token {
    vector<vector<int>> grid;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.constructProductMatrix(data.grid);
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
    tokens.push_back({{{1,2},{3,4}}, {{24,12},{8,6}}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}