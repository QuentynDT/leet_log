#include "../../timer.h"
class Solution {
public:
    struct DSU {
        vector<int> parent;
        vector<int> rank;

        DSU(int n) : parent(n), rank(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int u, int v) {
            const int i = find(u);
            const int j = find(v);
            if (i == j) return;
            
            if (rank[i] < rank[j]) {
                rank[j] += rank[i];
                parent[i] = j;
            } else {
                rank[i] += rank[j];
                parent[j] = i;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int n = accounts.size();
        vector<vector<string>> ans;
        unordered_map<string, int> emailToIndex;
        unordered_map<int, set<string>> indexToEmails;
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string email = accounts[i][j];
                auto it = emailToIndex.find(email);
                if (it == emailToIndex.end()) {
                    emailToIndex[email] = i;
                } else {
                    dsu.unite(i, it->second);
                }
            }
        }

        for (const auto& [email, index] : emailToIndex) {
            indexToEmails[dsu.find(index)].insert(email);
        }

        for (const auto& [index, emails] : indexToEmails) {
            const string name = accounts[index][0];
            vector<string> row{name};
            row.insert(row.end(), emails.begin(), emails.end());
            ans.push_back(row);
        }

        return ans;
    }
};

struct token {
    vector<vector<string>> accounts;
    vector<vector<string>> ans;
    vector<vector<string>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.accountsMerge(data.accounts);
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
    tokens[0] = {{{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}}, {{"John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}