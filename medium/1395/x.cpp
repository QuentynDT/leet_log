#include "../../timer.h"

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        const int n = rating.size();
        for (int i = 1; i < n - 1; i++) {
            vector<int> v(2, 0);
            int lg = 0;
            int rg = 0;
            for (int j = 0; j < i; j++){
                v[0] += rating[j] < rating[i];
            }
            for (int j = i + 1; j < n; j++){
                v[1] += rating[j] < rating[i];
            }
            ans += v[0] * (n - i - 1) + v[1] * (i - 2 * v[0]);
        }

        return ans;
    }
};

struct token {
    vector<int> rating;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.numTeams(data.rating);
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
    tokens[0] = {{2,5,3,4,1}, 3};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}