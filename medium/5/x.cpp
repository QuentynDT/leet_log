#include "../../timer.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        string t = "/";
        for(int i = 0; i < n; i++){
            t += "_";
            t += s[i];
        }
        t += "_\\";
        int maxPalindromeLength = 0, bestCenter = -1;
        const int sz = n * 2 + 3;
        vector<int> p(sz);
        int center = 0;
        for (int i = 1; i < sz - 1; i++) {
            const int rightBoundary = center + p[center];
            const int mirrorIndex = center - (i - center);
            if (rightBoundary > i)
                p[i] = min(rightBoundary - i, p[mirrorIndex]);
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                ++p[i];
            if (i + p[i] > rightBoundary)
                center = i;
            cout << " i is " << i << ", ti is " << t[i] << ", pi is " << p[i] << ", center is " << center << '\n';
        }
        for (int i = 0; i < sz; ++i){
            if (p[i] > maxPalindromeLength) {
                maxPalindromeLength = p[i];
                bestCenter = i;
            }
        }

        const int l = (bestCenter - maxPalindromeLength) / 2;
        const int r = (bestCenter + maxPalindromeLength) / 2;
        return s.substr(l, r - l);
    }
};

struct token {
    string s;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestPalindrome(data.s);
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
    tokens[0] = {"babad", "bab"};
    tokens[1] = {"cbbd", "bb"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}