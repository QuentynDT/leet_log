#include "../../timer.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int n = nums.size();
        int thr = 
        return {0, 1, 2, 3, 4, 5};
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.majorityElement(data.nums);
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
    tokens[0] = {{3, 2, 3}, {3}};
    tokens[1] = {{1}, {1}};
    tokens[2] = {{1, 2}, {1, 2}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}