#include "../../timer.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        if(n > m) return isInterleave(s2, s1, s3);
        vector<bool> dp(n + 1);

        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 && j == 0)
                    dp[j] = true;
                else if (i == 0)
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
                else
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1] || dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        return dp[n];
    }
};

struct token {
    string s1;
    string s2;
    string s3;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isInterleave(data.s1, data.s2, data.s3);
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
    tokens[0] = {"aabcc", "dbbca", "aadbbcbcac", true};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}