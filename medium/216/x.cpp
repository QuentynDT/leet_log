#include "../../timer.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        auto dfs = [&](this auto self, int x,int t) -> void {
            if(curr.size() == k){
                if(t == 0)
                ans.push_back(curr);
                return;
            }
            if(x > min(9, t) || t < 0) return;
            curr.push_back(x);
            self(x + 1, t - x);
            curr.pop_back();
            self(x + 1, t);
        };
        dfs(1, n);
        return ans;
    }
};

struct token {
    int k;
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.combinationSum3(data.k, data.n);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {3, 7, {{1,2,4}}};
    tokens[1] = {3, 9, {{1,2,6},{1,3,5},{2,3,4}}};
    tokens[2] = {4, 1, {{}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}