#include "../../timer.h"

class Solution {
public:
    int findNthDigit(int n) {
        int d = 1;
        long c = 9;

        while (c * d < n) {
            n -= c * d++;
            c *= 10;
        }

        int t = c/9 + (n - 1) / d;
        const int i = (n - 1) % d;
        for (int j = 0; j < d - i - 1; j++) {
            t /= 10;
        }
        return t % 10;
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.findNthDigit(data.n);
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
    const int n = 4;
    vector<token> tokens(n);
    tokens[0] = {3, 3};
    tokens[1] = {14, 1};
    tokens[2] = {15, 2};
    tokens[3] = {INT_MAX, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}