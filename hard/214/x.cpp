#include "../../timer.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string r = s;
        reverse(r.begin(), r.end());
        string ss = s + "#" + r;
        vector<int> next(ss.length(), 0);
        for (int i = 1, j = 0; i < ss.length(); i++) {
            while (j > 0 && ss[i] != ss[j])
                j = next[j - 1];
            if (ss[i] == ss[j])
                j++;
            next[i] = j;
        }
        for(int& x : next){
            cout << x << ' ';
        }
        cout << '\n';
        string suffix = s.substr(next.back());
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};

struct token {
    string s;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.shortestPalindrome(data.s);
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
    tokens[0] = {"aacecaaa", "aaacecaaa"};
    tokens[1] = {"abcd", "dcbabcd"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}