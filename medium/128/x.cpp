#include "../../timer.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int ml = 0;
        for (int num : seen) {
            if (!seen.count(num - 1)) {
                int curr = num, l = 1;
                while (seen.count(curr + 1)) {
                    curr++;
                    l++;
                }
                ml = max(ml, l);
            }
        }
        return ml;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestConsecutive(data.nums);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {{100,4,200,1,3,2}, 4};
    tokens[1] = {{0,3,7,2,5,8,4,6,0,1}, 9};
    tokens[2] = {{1,0,1,2}, 3};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
