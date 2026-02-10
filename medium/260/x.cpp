#include "../../timer.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const unsigned int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        const unsigned int low = x & -x;
        vector<int> ans(2);
        for (const int num : nums){
            if (num & low) ans[0] ^= num;
            else ans[1] ^= num;
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.singleNumber(data.nums);
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
    vector<token> tokens(n);
    tokens[0] = {{1, 1, 0, -2147483648}, {0, -2147483648}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}