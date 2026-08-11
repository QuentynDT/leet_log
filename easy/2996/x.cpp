#include "../../timer.h"

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const unordered_set<int> ns{nums.begin(), nums.end()};
        int ans = nums[0];
        const int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) break;
            ans += nums[i];
        }
        while (ns.contains(ans)) ans++;
        return ans;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.missingInteger(data.nums);
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
    tokens.push_back({{1, 2, 3, 2, 5}, 6});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
