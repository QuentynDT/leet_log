#include "../../timer.h"

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        unordered_map<int, int> pre;
        int ans = 0;
        // for(int i = 0; i < n; i++){
        //     if(costs[i] >= budget) continue;
        //     ans = max(ans, capacity[i] + pre[budget - costs[i] - 1]);
        //     cout << pre[budget - costs[i] - 1] << '\n';
        //     pre[costs[i]] = max(pre[costs[i]], capacity[i]);
        //     cout << "After " << i << ", ans is " << ans << '\n';
        // }
        const int sz = ranges::max(costs) + 1;
        vector<int> align(sz, -1);
        for(int i = 0; i < n; i++){
            align[costs[i]] = capacity[i];
        }
        for(int i = 0; i < sz; i++){
            auto it = upper_bound(align.begin(), align.end(), align[i]);
            ans = max(ans, ans);
        }
        return ans;
    }
};

struct token {
    vector<int> costs;
    vector<int> capacity;
    int budget;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxCapacity(data.costs, data.capacity, data.budget);
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
    tokens[0] = {{4,8,5,3}, {1, 5, 2, 7}, 8, 8};
    tokens[1] = {{6, 3}, {6, 1}, 12, 7};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}