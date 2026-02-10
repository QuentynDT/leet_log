#include "../../timer.h"

class Solution {
public:
    bool isHappy(int n) {
        while (n > 9) {
            int sum = 0;
            while (n > 0) {
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }
            n = sum;
        }
        return n == 1 || n == 7;
    }
};

struct token {
    int n;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isHappy(data.n);
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
    tokens[0] = {19, 1};
    tokens[1] = {2, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}