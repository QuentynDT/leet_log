#include "../../timer.h"

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        constexpr int kMod = 1'000'000'007;
        const int mx = ranges::max(nums);
        long long ans = 0;
        vector<int> count(mx + 1);
        for(const int& x : nums){
            count[x]++;
        }
        for(int i = 1; i <= mx; i++){
            count[i] += count[i - 1];
        }
        for(int i = 1; i <= mx; i++){
            if(count[i] > count[i - 1]){
                long long sum = 0;
                for (int j = 1; i * j <= mx; ++j) {
                    const int lo = i * j - 1, hi = i * (j + 1) - 1;
                    sum += (count[min(hi, mx)] - count[lo]) * j;
                }
                ans += sum * (count[i] - count[i - 1]);
                ans %= kMod;
            }
        }
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
    data.res = s.sumOfFlooredPairs(data.nums);
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
    tokens.push_back({{2, 5, 9}, 10});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
