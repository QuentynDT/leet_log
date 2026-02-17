#include "../../timer.h"

class Solution {
public:
    struct DSU {
        vector<int> parent;
        vector<int> rank;

        DSU(int n) : parent(n), rank(n, 0) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int u, int v) {
            const int i = find(u);
            const int j = find(v);
            if (i == j) return false;

            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else if (rank[i] > rank[j]) {
                parent[j] = i;
            } else {
                parent[i] = j;
                ++rank[j];
            }
            return true;
        }
    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<int> ins(n + 1, 0);
        int ntp = 0;

        for (const auto& edge : edges) {
            if (++ins[edge[1]] == 2) {
                ntp = edge[1];
                break;
            }
        }
        if (ntp == 0) {
            return findConnection(edges, -1);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (edges[i][1] == ntp) {
                if (findConnection(edges, i).empty()) {
                    return edges[i];
                }
            }
        }
        return {};
    }
    vector<int> findConnection(const vector<vector<int>>& edges, int skip) {
        const int n = edges.size();
        DSU dsu(n + 1);
        for (int i = 0; i < n; i++) {
            if (i == skip) continue;
            if (!dsu.unite(edges[i][0], edges[i][1])) {
                return edges[i];
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
    data.res = s.findRedundantDirectedConnection(data.edges);
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
    tokens[0] = {{{1,2},{2,3},{3,4},{4,1},{1,5}}, {4, 1}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}