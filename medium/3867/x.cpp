#include "../../timer.h"

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0, ans = 0;
        const int n = nums.size();
        vector<int> pf(n);
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            pf[i] = gcd(mx, nums[i]);
            cout << pf[i] << ' ';
        }
        cout << '\n';
        ranges::sort(pf);
        for(int i = 0; i < n / 2; i++){
            ans += gcd(pf[i], pf[n - i - 1]);
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.gcdSum(data.nums);
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
    tokens.push_back({{2, 6, 4}, 2});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
