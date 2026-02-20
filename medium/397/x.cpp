#include "../../timer.h"

class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        long long x = n;
        while(x > 3){
            if(x & 1){
                if((x & 0x3) == 3) {
                    x++;
                } else {
                    x--;
                }
            } else {
                x >>= 1;
            }
            ans++;
        }
        return ans + x - 1;
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.integerReplacement(data.n);
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
    const int n = 4;
    vector<token> tokens(n);
    tokens[0] = {8, 3};
    tokens[1] = {7, 4};
    tokens[2] = {4, 2};
    tokens[3] = {INT_MAX, 32};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}