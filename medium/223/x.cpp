#include "../../timer.h"

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
    }
};

struct token {
    int ax1;
    int ay1;
    int ax2;
    int ay2;
    int bx1;
    int by1;
    int bx2;
    int by2;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.computeArea(data.ax1, data.ay1, data.ax2, data.ay2, data.bx1, data.by1, data.bx2, data.by2);
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
    tokens[0] = {{-3, 0, 3, 4, 0, -1, 9, 2}, 45};
    tokens[1] = {{-2, -2, 2, 2, -2, -2, 2, 2}, 16};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}