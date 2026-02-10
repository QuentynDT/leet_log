#include "../../timer.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if(n < 3) return 0;
        int pd = nums[1] - nums[0], cd;
        for(int i = 2; i < n; i++){

        }
        vector<int> ds(n - 1);
        int curr = 1, ans = 0;
        for(int i = 0; i < n - 1; i++){
            ds[i] = nums[i + 1] - nums[i];
            cout << ds[i] << '\n';
            if(i == 0 || ds[i] == ds[i - 1]){
                curr++;
            } else {
                cout << curr << " is curr\n";
                ans += ((curr - 2) * (curr - 1)) / 2;
                curr = 1;
            }
        }
        return ans + ((curr - 2) * (curr - 1)) / 2;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.numberOfArithmeticSlices(data.nums);
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
    tokens[0] = {{1, 2, 3, 4}, 3};
    tokens[1] = {{1, 2, 3, 4, 6, 7, 8, 9}, 6};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}