#include "../../timer.h"

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        const int n = workerTimes.size();
        int mx = ranges::max(workerTimes);
        long long l = 0, r = 1LL * (1LL * mountainHeight * (mountainHeight + 1)) / 2 * mx;
        auto f = [&](long long t) -> int {
            int ans = 0;
            for(int i = 0; i < n; i++){
                ans += ((int)(sqrt(1 + 8 * t/workerTimes[i]) - 1))/2;
            }
            return ans;
        };
        while(l < r){
            long long m = (l + (r - l)/2);
            int sum = f(m);
            if(sum < mountainHeight){
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

struct token {
    int mountainHeight;
    vector<int> workerTimes;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.minNumberOfSeconds(data.mountainHeight, data.workerTimes);
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
    tokens.push_back({4, {2, 1, 1}, 3});
    tokens.push_back({100000, {1000000}, 5000050000000000});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}