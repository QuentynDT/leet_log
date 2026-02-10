#include "../../timer.h"
class Solution {
public:
    string decode(const string& s, int& i) {
        string result;
        int n = s.size();
        while (i < n && s[i] != ']') {
            if (isdigit(s[i])) {
                int k = 0;
                while (i < n && isdigit(s[i])) {
                    k = k * 10 + (s[i++] - '0');
                }
                i++;
                string sub = decode(s, i);
                i++;
                for (int count = 0; count < k; ++count) {
                    result += sub;
                }
            }
            else {
                result += s[i++];
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};
struct token {
    string s;
    string ans;
    string res;
};
int main(){
    
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {"3[a]2[bc]", "aaabcbc"};
    tokens[1] = {"3[a2[c]]", "accaccacc"};
    tokens[2] = {"2[abc]3[cd]ef", "abcabccdcdcdef"};
    auto handle = [&](token& data) -> void {
        Solution s;
        data.res = s.decodeString(data.s);
    };
    auto runTests = [&]() -> void {
        cout << '\n';
        for(int i = 0; i < n; i++){
            handle(tokens[i]);
            cout << "Output: ";
            display(tokens[i].res);
            cout << "Expected answer: ";
            display(tokens[i].ans);
            cout << '\n';
        }
    };
    auto start = high_resolution_clock::now();
    runTests();
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}