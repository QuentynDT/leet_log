#include "../../timer.h"

        //1101
        //1110
        //111
        //1000
        //100
        //10
        //1

        //0111010001
        //0111010010
        //011101001
        //011101010
        //01110101
        //01110110
        //0111011
        //0111100
        //011110
        //01111
        //10000
        //1000
        //100
        //10
        //1
class Solution {
public:
    int numSteps(string s) {
        const int n = s.size();
        int ans = 0, carry = 0;
        for (int i = n - 1; i > 0; i--) {
            if ((s[i] - '0') + carry == 1) {
                ans += 2;
                carry = 1;
            } else {
                ans += 1;
            }
        }
        return ans + carry;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.numSteps(data.s);
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
    tokens[0] = {"1101", 6};
    tokens[1] = {"10", 1};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}