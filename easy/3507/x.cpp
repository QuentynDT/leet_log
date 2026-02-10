#include "../../timer.h"

class Solution {
public:
    int ms (const vector<int>& nums) {
        int mn = INT_MAX;
        int index = -1;
        for(int i = 0; i + 1 < nums.size(); i++) {
            if(nums[i] + nums[i + 1] < mn) {
                index = i;
                mn = nums[i] + nums[i + 1];
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            ans++;
            int i = ms(nums);
            nums[i] = nums[i] + nums[i+1];

            nums.erase(begin(nums) + i + 1);
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
    data.res = s.minimumPairRemoval(data.nums);
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
    tokens[0] = {{5, 2, 3, 1}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}