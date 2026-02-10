#include "../../timer.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        ranges::sort(candidates);
        const int n = candidates.size();
        auto dfs = [&](this auto self, int start, int t) -> void {
            if (t == 0) {
                ans.push_back(curr);
                return;
            }

            for (int i = start; i < n; i++) {
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                if (candidates[i] > t) break;
                curr.push_back(candidates[i]);
                self(i + 1, t - candidates[i]);
                curr.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};

struct token {
    vector<int> candidates;
    int target;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.combinationSum2(data.candidates, data.target);
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
    tokens[0] = {{10,1,2,7,6,1,5}, 8, {{1,1,6},{1,2,5},{1,7},{2,6}}};
    tokens[1] = {{2,5,2,1,2}, 5, {{1,2,2},{5}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}