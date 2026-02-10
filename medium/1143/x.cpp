#include "../../timer.h"

class Solution {
public:
    void d(vector<vector<int>>& dp){
        for(const auto& v : dp){
            for(const auto& x : v){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.length(), n = text2.length();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= m; i++){
            int prev = dp[0]; 
            for(int j = 1; j <= n; j++){
                int curr = text1[i - 1] == text2[j - 1] ? 1 + prev : max(dp[j], dp[j - 1]);
                prev = dp[j];
                dp[j] = curr;
            }
        }
        return dp[n];
    }
};

struct token {
    string text1;
    string text2;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestCommonSubsequence(data.text1, data.text2);
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
    tokens[0] = {"house", "ros", 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}