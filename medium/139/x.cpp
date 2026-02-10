#include "../../timer.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        const unordered_set<string> words{wordDict.begin(), wordDict.end()};
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && words.contains(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }

        return dp[n];
    }
};

struct token {
    string s;
    vector<string> wordDict;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.wordBreak(data.s, data.wordDict);
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
    tokens[0] = {"leetcode", {"leet","code"}, true};
    tokens[1] = {"applepenapple", {"apple","pen"}, true};
    tokens[2] = {"catsandog", {"cats","dog","sand","and","cat"}, false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}