#include "../../timer.h"

class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int ri = find(i);
            int rj = find(j);
            if (ri != rj) {
                parent[ri] = rj;
                return true;
            }
            return false;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for (auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};

struct token {
    vector<vector<int>> edges;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.findRedundantConnection(data.edges);
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
    tokens[0] = {{{1,2},{1,3},{2,3}}, {2, 3}};
    tokens[1] = {{{1,2},{2,3},{3,4},{1,4},{1,5}}, {1,4}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}