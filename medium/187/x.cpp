#include "../../timer.h"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int n = s.size();
        if (n < 10) return {};
        static bitset<1<<20> seen;
        static bitset<1<<20> done;
        seen.reset();
        done.reset();
        vector<string> ans;
        int cmap[128];
        cmap['A'] = 0;
        cmap['C'] = 1;
        cmap['G'] = 2;
        cmap['T'] = 3;
        int mask = 0xFFFFF, curr = 0;
        for (int i = 0; i < 10; ++i) {
            curr = (curr << 2) | cmap[s[i]];
        }
        seen.set(curr);
        for (int i = 10; i < n; i++) {
            curr = ((curr << 2) & mask) | cmap[s[i]];
            if (done.test(curr)) {
                continue;
            }
            if (seen.test(curr)) {
                if(!done.test(curr)){
                    ans.push_back(s.substr(i - 9, 10));
                    done.set(curr);
                }
            } else {
                seen.set(curr);
            }
        }
        return ans;
    }
};

struct token {
    string s;
    vector<string> ans;
    vector<string> res;
};

void handle(token& data){
    Solution s;
    data.res = s.findRepeatedDnaSequences(data.s);
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
    tokens[0] = {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC","CCCCCAAAAA"}};
    tokens[1] = {"AAAAAAAAAAAAA", {"AAAAAAAAAA"}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}