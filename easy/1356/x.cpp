#include "../../timer.h"

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> bucket(15);
        for(int& num : arr) {
            bucket[__builtin_popcount(num)].push_back(num);
        }
        vector<int> ans;
        ans.reserve(arr.size());
        for(auto &v : bucket) {
            ranges::sort(v);
            ans.insert(ans.end(), make_move_iterator(v.begin()), make_move_iterator(v.end()));
        }
        return ans;
    }
};
struct token {
    vector<int> arr;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.sortByBits(data.arr);
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
    tokens[0] = {{0,1,2,3,4,5,6,7,8}, {0,1,2,4,8,3,5,6,7}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}