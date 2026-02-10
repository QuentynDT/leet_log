#include "../../timer.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<unsigned int, size_t> mtl;
        
        for (const string& w : words) {
            unsigned int mask = 0;
            for (char c : w) {
                mask |= (1 << (c - 'a'));
            }
            mtl[mask] = max(mtl[mask], w.size());
        }
        
        size_t ans = 0;
        
        for (auto const& [mask1, n1] : mtl) {
            for (auto const& [mask2, n2] : mtl) {
                if (mask1 & mask2) continue;
                ans = max(ans, n1 * n2);
            }
        }
        
        return ans;
    }
};

struct token {
    vector<string> words;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxProduct(data.words);
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
    tokens[0] = {{"abcw","baz","foo","bar","xtfn","abcdef"}, 16};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}