#include "../../timer.h"

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        const int n = nums.size();
        auto f = [&](int x) -> bool {
            int cnt = 0, j = n;
            for (int i = 0; i < n; i++) {
                if (nums[i] > x || i == j + 1) {
                    continue;
                }
                cnt++;
                j = i;
            }
            return cnt >= k;
        };
        int left = 0, right = ranges::max(nums);
        while (left < right) {
            int mid = (left + right) >> 1;
            if (f(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
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
    data.res = s.minCapability(data.nums, data.k);
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
    tokens[0] = {{2,7,9,3,1}, 2, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}