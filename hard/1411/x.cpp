#include "../../timer.h"

class Solution {
public:
    void d(vector<vector<vector<int>>>& dp){
        for(const auto& l: dp){
            for(const auto& v : l){
                for(const int& i : v){
                    cout << i << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }
    int numOfWays(int n) {
        static constexpr int kMod = 1'000'000'007;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3)));
        d(dp);
        return 0;
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.numOfWays(data.n);
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
    tokens[0] = {1, 12};
    tokens[1] = {2, 54};
    tokens[2] = {3, 246};
    //tokens[1] = {5000, 30228214};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}