#include "../../timer.h"

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> prefixToBlocks;
        for (const string& a : allowed)
            prefixToBlocks[a.substr(0, 2)].push_back(a[2]);
        
        unordered_map<string, bool> memo;
        return dfs(bottom, "", 0, prefixToBlocks, memo);
    }

private:
    bool dfs(const string& row, const string& nextRow, int i,
             const unordered_map<string, vector<char>>& prefixToBlocks,
             unordered_map<string, bool>& memo) {
        
        if (row.length() == 1) return true;

        if (nextRow.length() + 1 == row.length()) {
            if (memo.count(nextRow)) return memo[nextRow];
            return memo[nextRow] = dfs(nextRow, "", 0, prefixToBlocks, memo);
        }

        const string prefix = row.substr(i, 2);
        if (prefixToBlocks.count(prefix)) {
            for (const char c : prefixToBlocks.at(prefix)) {
                if (dfs(row, nextRow + c, i + 1, prefixToBlocks, memo))
                    return true;
            }
        }

        return false; 
    }
};

struct token {
    string bottom;
    vector<string> allowed;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.pyramidTransition(data.bottom, data.allowed);
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
    tokens[0] = {"BCD", {"BCC","CDE","CEA","FFF"}, true};
    tokens[1] = {"AAAA", {"AAB","AAC","BCD","BBE","DEF"}, false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}