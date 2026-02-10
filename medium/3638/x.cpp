#include "../../timer.h"

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        stack<int> st;
        const int n = weight.size();
        vector<int> next(n, -1);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && weight[st.top()] < weight[i]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            if(next[i] != -1) {
                dp[next[i]] = max(dp[next[i]], 1 + dp[i + 1]);
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        // for(int i = 0; i < n; i++){
        //     cout << weight[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << next[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << '\n';
        return dp[0];
    }
};

struct token {
    vector<int> weight;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxBalancedShipments(data.weight);
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
    tokens[0] = {{2, 5, 1, 4, 3}, 2};
    tokens[1] = {{483,199,268,147,415,510}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}