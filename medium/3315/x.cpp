#include "../../timer.h"

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int& x : nums){
            if(x % 2 == 0){
                x = -1;
                continue;
            }
            x &= ~((x + 1) & ~x) >> 1;
        }
        return nums;
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.minBitwiseArray(data.nums);
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
    tokens[0] = {{2,3,5,7}, {-1, 1, 4, 3}};
    tokens[1] = {{11, 13, 31}, {9, 12, 15}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}