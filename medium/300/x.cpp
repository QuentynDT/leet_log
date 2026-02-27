#include "../../timer.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        auto findPos = [&](int idx) -> int {
            return ranges::lower_bound(seq, idx) - seq.begin();
        };
        for (const int& num : nums)
        if (seq.empty() || num > seq.back()){
            seq.push_back(num);
        } else {
            seq[findPos(num)] = num;
        }
        return seq.size();
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.lengthOfLIS(data.nums);
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
    tokens[0] = {{10,9,2,5,3,7,101,18}, 4};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}