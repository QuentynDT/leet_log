#include "../../timer.h"

class Solution {
public:
    struct DSU {
        unordered_map<string, string> parent;
        unordered_map<string, double> weight;

        void add(string x) {
            if (parent.count(x)) return;
            parent[x] = x;
            weight[x] = 1.0;
        }

        string find(string i) {
            if (parent[i] == i) return i;
            string root = find(parent[i]);
            weight[i] *= weight[parent[i]];
            return parent[i] = root;
        }

        void unite(string i, string j, double value) {
            string ri = find(i);
            string rj = find(j);
            if (ri != rj) {
                parent[ri] = rj;
                weight[ri] = (weight[j] / weight[i]) * value;
            }
        }
    };

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU dsu;
        const int n = equations.size();
        for (int i = 0; i < n; i++) {
            dsu.add(equations[i][0]);
            dsu.add(equations[i][1]);
            dsu.unite(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for (const auto& q : queries) {
            if (!dsu.parent.count(q[0]) || !dsu.parent.count(q[1])) {
                ans.push_back(-1.0);
            } else {
                string root1 = dsu.find(q[0]);
                string root2 = dsu.find(q[1]);
                if (root1 != root2) {
                    ans.push_back(-1.0);
                } else {
                    ans.push_back(dsu.weight[q[0]] / dsu.weight[q[1]]);
                }
            }
        }
        return ans;
    }
};

struct token {
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    vector<double> ans;
    vector<double> res;
};

void handle(token& data){
    Solution s;
    data.res = s.calcEquation(data.equations, data.values, data.queries);
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
    tokens[0] = {{{"a","b"},{"b","c"}}, {2.0,3.0}, {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}, {6.00000,0.50000,-1.00000,1.00000,-1.00000}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}