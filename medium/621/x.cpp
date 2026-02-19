#include "../../timer.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int mx = 0, cmf = 0;
        const int sz = tasks.size();
        for (char& t : tasks) {
            freq[t - 'A']++;
        }
        for (int& f : freq) {
            if (f > mx) {
                mx = f;
                cmf = 1;
            } else if (f == mx) {
                cmf++;
            }
        }
        return max((mx - 1) * (n + 1) + cmf, sz);
    }
};

struct token {
    vector<char> tasks;
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.leastInterval(data.tasks, data.n);
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
    tokens[0] = {{'A','A','A','C','C','C','B','B','B'}, 2, 9};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}