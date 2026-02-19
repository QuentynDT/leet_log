#include "../../timer.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        for(int i = 0; i < arrays.size(); i++){
            maxHeap.push({arrays[i].front(), i});
            if (maxHeap.size() > 2) {
                maxHeap.pop();
            }
            minHeap.push({arrays[i].back(), i});
            if (minHeap.size() > 2) {
                minHeap.pop();
            }
        }
        auto [v1, i1] = minHeap.top();
        auto [v3, i3] = maxHeap.top();
        minHeap.pop(); maxHeap.pop();
        auto [v2, i2] = minHeap.top();
        auto [v4, i4] = maxHeap.top();

        // cout << "v1 " << v1 << " v2 " << v2 << " v3 " << v3 << " v4 " << v4 << '\n';
        // cout << "i1 " << i1 << " i2 " << i2 << " i3 " << i3 << " i4 " << i4 << '\n';
        if(i2 != i4){
            return abs(v2 - v4);
        }
        return max(abs(v1 - v4), abs(v2 - v3));
    }
};

struct token {
    vector<vector<int>> arrays;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxDistance(data.arrays);
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
    tokens[0] = {{{1,2,3},{4,5},{1,2,3}}, 4};
    tokens[1] = {{{0, 2, 5}, {4, 9}}, 9};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}