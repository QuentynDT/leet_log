#include "../../timer.h"

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> freq;
        for(int& x : arr){
            freq[x]++;
        }
        map<int, vector<int>> m;
        for(auto & [x, f] : freq){
            m[f].push_back(x);
        }
        int target = arr.size() / 2, ans = 0;
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            for(int& x : it->second){
                ans++;
                target -= it->first;
                if(target < 0) return ans;
            }
        }
        throw;
    }
};

struct token {
    vector<int> arr;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minSetSize(data.arr);
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
    vector<token> tokens;
    tokens.push_back({{3,3,3,3,5,5, 5,5,2,2,7}, 2});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}