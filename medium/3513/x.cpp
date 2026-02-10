#include "../../timer.h"

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const unsigned int n = nums.size();
        if(n <= 2) return n;
        return 1 << bit_width(n);
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.uniqueXorTriplets(data.nums);
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
    tokens[0] = {{1, 2}, 2};
    tokens[1] = {{1}, 1};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}