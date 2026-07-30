#include "../../timer.h"

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long total = accumulate(beans.begin(), beans.end(), 0LL), mx = 0;
        const int n = beans.size();
        ranges::sort(beans);
        for(int i = 0; i < n; i++){
            //each bag has beans[i] beans;
            long long left = 1LL * beans[i] * (n - i);
            mx = max(mx, left);
        }
        return total - mx;
    }
};

struct token {
    vector<int> beans;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.minimumRemoval(data.beans);
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
    tokens.push_back({{4,1,6,5}, 4});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
