#include "../../timer.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int j = 0; j < n; j++){
            if (p[j] != '*') break;
            dp[0][j + 1] = true;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(p[j] == '*'){
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
                } else if(p[j] == '?' || p[j] == s[i]){
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

struct token {
    string s;
    string p;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isMatch(data.s, data.p);
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
    tokens.push_back({"aa", "a", false});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}