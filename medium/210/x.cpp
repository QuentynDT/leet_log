#include "../../timer.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);
        for (const auto& edge : prerequisites) {
            int v = edge[0];
            int u = edge[1];
            adj[u].push_back(v);
            in[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        int vc = 0;
        while (!q.empty()) {
            int curr = q.front();
            ans[vc++] = curr;
            q.pop();

            for (int x : adj[curr]) {
                in[x]--;
                if (in[x] == 0) {
                    q.push(x);
                }
            }
        }
        return vc == numCourses ? ans : vector<int>{};
    }
};

struct token {
    int numCourses;
    vector<vector<int>> prerequisites;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.findOrder(data.numCourses, data.prerequisites);
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
    tokens[0] = {2, {{1,0}}, {0, 1}};
    tokens[1] = {4, {{1,0},{2,0},{3,1},{3,2}}, {0, 1, 2, 3}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}