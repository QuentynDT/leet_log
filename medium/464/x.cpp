#include "../../timer.h"

class Solution {
public:
    bool canIWin(int mci, int dt) {
        signed char memo[1 << 20];
        if ((mci * (mci + 1) / 2) < dt) return false;
        if (dt <= 0) return true;
        memset(memo, -1, sizeof(signed char) * (1 << mci));

        auto dfs = [&](this auto self, int mask, int target) -> bool {
            if (memo[mask] != -1) return memo[mask];
            if ((32 - __builtin_clz(mask)) >= target) 
            return memo[mask] = 1;

            for (int temp = mask; temp; temp &= temp - 1) {
                int i = __builtin_ctz(temp);
                if(!self(mask ^ (1 << i), target - i - 1)) {
                    return memo[mask] = 1;
                }
            }
            return memo[mask] = 0;
        };
        return dfs((1 << mci) - 1, dt);
    }
};

struct token {
    int maxChoosableInteger;
    int desiredTotal;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.canIWin(data.maxChoosableInteger, data.desiredTotal);
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
    tokens[0] = {10, 11, false};
    tokens[1] = {10, 0, true};
    tokens[2] = {10, 1, true};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}