#include "../../timer.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        const int n = adj.size();
        vector<int> color(n, 0);
        
        auto dfs = [&](this auto self, int u, int c) -> bool {
            color[u] = c;
            for (int v : adj[u]) {
                if (color[v] == c) return false;
                if (color[v] == 0 && !self(v, -c)) return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(i, 1)) return false;
        }
        return true;
    }
};

struct token {
    vector<vector<int>> graph;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isBipartite(data.graph);
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
    tokens[0] = {{{1,3},{0,2},{1,3},{0,2}}, true};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}