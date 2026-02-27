#include "../../timer.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0, mx = 0;
        vector<int> len(n, 1), count(n, 1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] >= nums[i]) continue;
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                } else if (len[i] == len[j] + 1) {
                    count[i] += count[j];
                }
            }
            mx = max(mx, len[i]);
        }
        for(int i = 0; i < n; i++){
            if(len[i] == mx){
                ans += count[i];
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
    data.res = s.findNumberOfLIS(data.nums);
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
    tokens[0] = {{1,3,5,4,7}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}