#include "../../timer.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        auto dfs = [&](this auto self, int i) -> void {
            ans.push_back(v);
            for(int j = i; j < n; j++){
                if(j > i && nums[j] == nums[j - 1]) continue;
                v.push_back(nums[j]);
                self(j + 1);
                v.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};

struct token {
    vector<int> nums;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.subsetsWithDup(data.nums);
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
    tokens[0] = {{1,2,2}, {{},{1},{1,2},{1,2,2},{2},{2,2}}};
    tokens[1] = {{0}, {{},{0}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}