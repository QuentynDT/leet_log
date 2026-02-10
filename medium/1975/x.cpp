#include "../../timer.h"

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        bool ec = true;
        int me = INT_MAX;
        for(const auto& v: matrix){
            for(const auto& x : v){
                if(x < 0) ec = !ec;
                const int y = abs(x);
                me = min(y, me);
                ans += y;
            }
        }
        if (ec) return ans;
        else return ans - 2 * me;
    }
};

struct token {
    vector<vector<int>> matrix;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxMatrixSum(data.matrix);
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
    tokens[0] = {{{1,-1},{-1,1}}, 4};
    tokens[1] = {{{1,2,3},{-1,-2,-3},{1,2,3}}, 16};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}