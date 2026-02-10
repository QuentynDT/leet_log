#include "../../timer.h"

class Solution {
public:
    void display(vector<vector<int>>& dp){
        for(const auto& v : dp){ 
            for(const auto& x : v){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        if (n < m) return minDistance(word2, word1);
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            dp[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int x = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int y = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = x;
                } else {
                    dp[j] = 1 + min({dp[j], dp[j - 1], x});
                }
                x = y;
            }
        }
        return dp[n];
    }
};

struct token {
    string word1;
    string word2;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minDistance(data.word1, data.word2);
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
    tokens[0] = {"horse", "ros", 3};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}