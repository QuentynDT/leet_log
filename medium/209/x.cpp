#include "../../timer.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int sum = 0, ans = n + 1, l = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};

struct token {
    int target;
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minSubArrayLen(data.target, data.nums);
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
    tokens[0] = {7, {2,3,1,2,4,3}, 2};
    tokens[1] = {4, {1,4,4}, 1};
    tokens[2] = {11, {1,1,1,1,1,1,1,1}, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}