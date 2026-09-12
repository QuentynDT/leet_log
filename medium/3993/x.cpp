#include "../../timer.h"

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        bool odd = (n % 2);
        n/=2;
        cout << n << '\n';
        int ans = s + (m - 1) * (n - 1) + m;
        cout << "ans is " << ans << '\n';
        if(odd){

            cout << "odd\n";
        } else {
            cout << "even\n";
        }
        return n;
    }
};

struct token {
    int n;
    int s;
    int m;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.maximumValue(data.n, data.s, data.m);
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
    tokens.push_back({4, 3, 5, 12});
    tokens.push_back({3, 2, 3, 2});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
