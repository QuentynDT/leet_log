#include "../../timer.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        const string s2 = ")" + s;
            // dp[i] := the size of the longest valid parentheses in the substring
            // s2[1..i]
        const int n = s2.size();
            vector<int> dp(s2.size());

            for (int i = 1; i < s2.size(); ++i)
              if (s2[i] == ')' && s2[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;

            return ranges::max(dp);
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestValidParentheses(data.s);
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
    vector<token> tokens;
    tokens.push_back({"(()", 2});
    tokens.push_back({")()())", 4});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
