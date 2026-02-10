#include "../../timer.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int r = 0, c = n - 1, ans = 0;
        while (r < m && c >= 0) {
            if (grid[r][c] < 0) {
                ans += (m - r);
                c--;
            } else {
                r++;
            }
        }
        return ans;
    }
};

struct token {
    vector<vector<int>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    display(data.grid);
    cout << '\n';
    data.res = s.countNegatives(data.grid);
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
    tokens[0] = {{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}, 8};
    tokens[1] = {{{3,2},{1,0}}, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}