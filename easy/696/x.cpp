#include "../../timer.h"

class Solution {
public:
  int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, curr = 1;
        const int n = s.size();
        for (int i = 0; i < n; i++)
        if (i == n - 1 || s[i] != s[i + 1]){
            ans += min(prev, curr);
            prev = curr;
            curr = 1;
        } else {
            curr++;
        }

        return ans;
    }
};
struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.countBinarySubstrings(data.s);
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
    tokens[0] = {"00110011", 6};
    tokens[1] = {"10101", 4};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}