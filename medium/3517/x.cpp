#include "../../timer.h"

class Solution {
public:
    string smallestPalindrome(string s) {
        const int n = s.size();
        string t, u;
        bool odd = n % 2;
        vector<int> alpha(26);
        for(int i = 0; i < n / 2; i++){
            alpha[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            t += string(alpha[i], i + 'a');
        }
        u.reserve(t.size() * 2 + odd);
        u.append(t);
        if(odd){
            u.push_back(s[n / 2]);
        }
        ranges::copy(t | views::reverse, back_inserter(u));
        return u;
    }
};

struct token {
    string s;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.smallestPalindrome(data.s);
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
    vector<token> tokens;
    tokens.push_back({"z", "z"});
    tokens.push_back({"babab", "abbba"});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
