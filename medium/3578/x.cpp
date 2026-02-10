#include "../../timer.h"

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
                cout << nums[dq.front()] << '\n';
            }
        }
        return dp[n - 1];
    }
};


struct token {
    vector<int> nums;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.countPartitions(data.nums, data.k);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "Expected answer: ";
        display(t.ans);
        cout << '\n';
    }
}

int main(){
    const int n = 2;
    vector<token> tokens(n);
    tokens[0] = {{9, 4, 1, 3, 7}, 4};
    tokens[1] = {{3, 3, 4}, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}