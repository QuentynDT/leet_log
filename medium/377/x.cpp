#include "../../timer.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++){
            for (const int& num : nums){
                if (i >= num){
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

struct token {
    vector<int> nums;
    int target;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.combinationSum4(data.nums, data.target);
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
    tokens[0] = {{1,2,3}, 4, 7};
    tokens[1] = {{9}, 3, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}