#include "../../timer.h"

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        ranges::sort(nums);
        unordered_map<int, int> seen;
        const int n = nums.size() / 2;
        for(int& x : nums){
            seen[x]++;
        }
        vector<int> ans(n, -1);
        auto solve = [&](int k, unordered_map<int, int> seen) -> void {
            int i = 0;
            for(int& x : nums){
                cout << "hey\n";
                if(seen[x] <= 0 ) continue;
                if(seen[x + 2 * k] <= 0) return;
                cout << x << " and " << x + 2 * k << " have been paired\n";
                seen[x]--;
                seen[x + 2 * k]--;
                cout << " now " << x << " has " << seen[x] << " and " << x + 2 * k << " has " << seen[x + 2 * k] << '\n';
                cout << i << '\n';
                ans[i++] = x + k;
            }
            for(int j = 0; j < i; j++){
                cout << ans[j] << ' ';
            }
            cout << '\n';
        };
        for(int i = 1; i < 2 * n; i++){
            int k = nums[i] - nums[0];
            if(k == 0 || k % 2 == 1) continue;
            cout << "hi, the current k is " << k/2 << "\n";
            solve(k / 2, seen);
            if(ans[n - 1] != -1) return ans;
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
    data.res = s.recoverArray(data.nums);
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
    tokens.push_back({{2, 10, 6, 4, 8, 12}, {3, 7, 11}});
    tokens.push_back({{1,50,99,101,150,199}, {51, 100, 149}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
