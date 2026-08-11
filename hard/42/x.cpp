#include "../../timer.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0, l = 0, r = height.size() - 1;
        int ml = height[l], mr = height[r];
        while(l < r){
            if (ml < mr) {
                ans += ml - height[l];
                ml = max(ml, height[++l]);
            } else {
                ans += mr - height[r];
                mr = max(mr, height[--r]);
            }
        }
        return ans;
    }
};

struct token {
    vector<int> height;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.trap(data.height);
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
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
