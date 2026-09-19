#include "../../timer.h"

class Solution {
public:
    string baseNeg2(int n) {
        string b = format("{:b}", n);
        int sz = b.size();
        if(sz % 2){
            sz++;
            b = "0" + b;
        }
        return b;
    }
};

struct token {
    int n;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.baseNeg2(data.n);
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
    tokens.push_back({2, "110"});
    tokens.push_back({3, "111"});
    tokens.push_back({6, "11010"});
    tokens.push_back({8, "11000"});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
