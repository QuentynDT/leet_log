#include "../../timer.h"

class Solution {
public:
    int flipLights(int n, int k) {
        n = min(n, 3);
        if (k == 0) return 1;
        if (k == 1) return n + 1;
        if (k == 2) return 1 + (n * n + n) / 2;
        return (1 << n);
    }
};

struct token {
    int n;
    int presses;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.flipLights(data.n, data.presses);
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
    tokens[0] = {10, 1, 4};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}