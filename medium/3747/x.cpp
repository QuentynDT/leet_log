#include "../../timer.h"

class Solution {
public:
    int cd(long long n) {
        return (int)log10(n + 1e-12) + 1;
    }
    long long countDistinct(long long n) {
        int x = cd(n);
        long long ans = 0;
        for(int i = 1; i < x; i++){
            ans += 9 * pow(10, i - 1) - pow(9, i);
        }
        return ans;
    }
};

struct token {
    long long n;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.countDistinct(data.n);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {10, 9};
    tokens[1] = {3, 3};
    tokens[2] = {32505, 21555};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}