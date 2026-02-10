#include "../../timer.h"

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e15;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        for (int i = cost.size() - 1; i >= 0; i--) {
            const int u = original[i] - 'a', v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = source.size() - 1; i >= 0; i--) {
            if (source[i] == target[i]) continue;
            
            long long c = dist[source[i] - 'a'][target[i] - 'a'];
            if (c >= INF) return -1;
            ans += c;
        }
        return ans;
    }
};

struct token {
    string source;
    string target;
    vector<char> original;
    vector<char> changed;
    vector<int> cost;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.minimumCost(data.source, data.target, data.original, data.changed, data.cost);
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
    tokens[0] = {"abcd", "acbe", {'a','b','c','c','e','d'}, {'b','c','b','e','b','e'}, {2, 5, 5, 1, 2, 20}, 28};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}