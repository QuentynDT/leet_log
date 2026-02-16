#include "../../timer.h"

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, 0);
        
        auto dfs = [&](this auto self, int u, int c) -> bool {
            color[u] = c;
            for (int v : adj[u]) {
                if (color[v] == c) return false;
                if (color[v] == 0 && !self(v, -c)) return false;
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            if (color[i] == 0 && !dfs(i, 1)) return false;
        }
        return true;
    }
};

struct token {
    int n;
    vector<vector<int>> dislikes;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.possibleBipartition(data.n, data.dislikes);
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
    tokens[0] = {4, {{1,2},{1,3},{2,4}}, true};
    tokens[1] = {5, {{1,2},{2,3},{3,4},{4,5},{1,5}}, false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}