#include "../../timer.h"

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 0) return 0;
        if(n == 1) return costs[0] + 1;
        vector<int> b(4);
        b[0] = 0;
        b[1] = costs[0] + 1;
        b[2] = costs[1] + min(b[1] + 1, b[0] + 4);
        for(int i = 2; i < n; i++){
            b[3] = costs[i] + min({b[2] + 1, b[1] + 4, b[0] + 9});
            b[0] = b[1];
            b[1] = b[2];
            b[2] = b[3];
        }
        return b[2];
    }
};

struct token {
    int n;
    vector<int> costs;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.climbStairs(data.n, data.costs);
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
    tokens[0] = {2, {4, 6}, 10};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}