#include "../../timer.h"

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;
        int x = -1;
        for(char &c : s){
            //cout << c << '\n';
            if(isdigit(c)){
                if(x == -1) x = 0;
                x * 10 + (c - '0');
                continue;
            }
            if(x != -1) nums.push_back(x);
            x = -1;
            if(c == ' ') continue;  
        }
        for(int& y : nums){
            cout << y << '\n';
        }
        return 0;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.calculate(data.s);
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
    tokens[0] = {"1 + 1", 2};
    tokens[1] = {" 2-1 + 2 ", 3};
    tokens[2] = {"(1+(4+5+2)-3)+(6+8)", 23};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}