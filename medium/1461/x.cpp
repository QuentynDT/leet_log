#include "../../timer.h"

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.size();
        if(n < k) return false;
        const int window = (1 << k) - 1;
        unordered_set<int> seen;
        int roll = 0;
        for(int i = 0; i < k; i++){
            roll = 2 * roll + (s[i] == '1');
        }
        seen.insert(roll);
        for(int i = k; i < n; i++){
            roll = ((roll << 1) & window) | (s[i] == '1');
            seen.insert(roll);
        }
        return (seen.size() == window + 1);
    }
};

struct token {
    string s;
    int k;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.hasAllCodes(data.s, data.k);
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
    tokens[0] = {"00110110", 2, true};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}