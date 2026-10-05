#include "../../timer.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), curr(k, 0);
        for (int& num : nums) {
            num %= k;
            vector<long long> next(k, 0);
            for (int i = 0; i < k; i++) {
                next[(i * num) % k] += curr[i];
            }
            next[num]++;
            for (int i = 0; i < k; i++) {
                ans[i] += next[i];
            }
            curr = move(next);
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int k;
    vector<long long> ans;
    vector<long long> res;
};

void handle(token& data) {
    Solution s;
    data.res = s.resultArray(data.nums, data.k);
}

void runTests(vector<token>& tokens) {
    cout << '\n';
    for(token& t : tokens) {
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main() {
    cout.imbue(locale(cout.getloc(), new CleanDoubleFacet));
    vector<token> tokens;
    tokens.push_back({{1, 2, 3, 4, 5}, 3, {9, 2, 4}});
    tokens.push_back({{1,2,4,8,16,32}, 4, {18, 1, 2, 0}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
    return 0;
}
