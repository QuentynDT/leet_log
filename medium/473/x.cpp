#include "../../timer.h"

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        const int n = matchsticks.size();
        if(n < 4) return false;
        int l = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        cout << l << '\n';
        if(l % 4 || l == 0) return false;
        l/=4;
        vector<int> sides(4, l);
        auto display = [](vector<int>& v) -> void {
            for(int& x : v){
                cout << x << ' ';
            }
            cout << '\n';
        };
        auto dfs = [&](this auto self, int i) -> bool {
            if(i == n) return true;
            for(int j = 0; j < 4; j++){
                if(matchsticks[i] <= sides[j]){
                    sides[j] -= matchsticks[i];
                    return (self(i + 1));
                    sides[j] += matchsticks[i];
                }
            }
            return false;
        };
        return dfs(0);
    }
};

struct token {
    vector<int> matchsticks;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.makesquare(data.matchsticks);
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
    tokens[0] = {{1,1,2,2,2}, true};
    tokens[1] = {{3,3,3,3,4}, false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}