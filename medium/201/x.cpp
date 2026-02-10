#include "../../timer.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};

struct token {
    int left;
    int right;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.rangeBitwiseAnd(data.left, data.right);
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
    tokens[0] = {5, 7, 4};
    tokens[1] = {12, 15, 12};
    tokens[2] = {1, 2147483647, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}