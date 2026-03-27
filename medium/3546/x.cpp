#include "../../timer.h"

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<long long> rs(m), cs(n);
        long long ts = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rs[i] += grid[i][j];
                cs[j] += grid[i][j];
                ts += grid[i][j];
            }
        }
        long long sum = 0;
        for(int i = 0; i < m; i++){
            sum += rs[i];
            if(sum * 2 == ts) return true;
        }
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += cs[i];
            if(sum * 2 == ts) return true;
        }
        return false;
    }
};

struct token {
    vector<vector<int>> grid;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.canPartitionGrid(data.grid);
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
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}