#include "../../timer.h"

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return 1;
        }
        unordered_set<int> pairs;
        bitset<1<<10> triplets;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairs.insert(nums[i] ^ nums[j]);
            }
        }
        for (int pairXor : pairs) {
            for (int num : nums) {
                triplets.set(pairXor ^ num);
            }
        }
        return triplets.count();
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.uniqueXorTriplets(data.nums);
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
    tokens[0] = {{1, 3}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}