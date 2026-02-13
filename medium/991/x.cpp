#include "../../timer.h"

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int o = 0;
        while (target > startValue) {
            o++;
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
        }
        return o + (startValue - target);
    }
};

struct token {
    int startValue;
    int target;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.brokenCalc(data.startValue, data.target);
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
    tokens[0] = {5, 8, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}