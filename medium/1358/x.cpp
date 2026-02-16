#include "../../timer.h"

class Solution {
 public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> count(3);
        int l = 0;
        for (const char& c : s) {
            count[c - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0){
                count[s[l++] - 'a']--;
            }
            ans += l;
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
    data.res = s.numberOfSubstrings(data.s);
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
    tokens[0] = {"abcabc", 10};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}