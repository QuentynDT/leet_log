#include "../../timer.h"

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int prev = 0;
        int curr = 0;
        char op = '+';

        for (int i = 0; i < s.length(); ++i) {
            const char c = s[i];
            if (isdigit(c))
                curr = curr * 10 + (c - '0');
            if (!isdigit(c) && !isspace(c) || i == s.length() - 1) {
                if (op == '+' || op == '-') {
                    ans += prev;
                    prev = op == '+' ? curr : -curr;
                } else if (op == '*') {
                    prev *= curr;
                } else if (op == '/') {
                    prev /= curr;
                }
                op = c;
                curr = 0;
            }
        }

        return ans + prev;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.calculate(data.s);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {"3+2*2", 7};
    tokens[1] = {" 3/2 ", 1};
    tokens[2] = {" 3+5 / 2 ", 5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}