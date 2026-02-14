#include "../../timer.h"

class Solution {
public:
    struct DSU {
        vector<int> parent;
        int components;
        DSU(int n) : components(n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int i, int j) {
            int ri = find(i);
            int rj = find(j);
            if (ri != rj) {
                parent[ri] = rj;
                components--;
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j] == 1) dsu.unite(i, j);
            }
        }
        return dsu.components;
    }
};

struct token {
    vector<vector<int>> isConnected;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.findCircleNum(data.isConnected);
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
    tokens[0] = {{{1,1,0},{1,1,0},{0,0,1}}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}