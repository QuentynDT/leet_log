#include "../../timer.h"

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
    }
};

struct token {
    vector<int> nums;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.gcdSum(data.nums);
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
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}