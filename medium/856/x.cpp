#include "../../timer.h"

class Solution {
public:
    int scoreOfParentheses(string s) {
        const int n = s.size();
        int score = 0, depth = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data) {
    Solution s;
    data.res = s.scoreOfParentheses(data.s);
}

void runTests(vector<token>& tokens) {
    cout << '\n';
    for(token& t : tokens) {
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main() {
    cout.imbue(locale(cout.getloc(), new CleanDoubleFacet));
    vector<token> tokens;
    tokens.push_back({"()", 1});
    tokens.push_back({"(())", 2});
    tokens.push_back({"()()", 2});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
    return 0;
}
