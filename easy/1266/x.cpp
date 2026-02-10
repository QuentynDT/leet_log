#include "../../timer.h"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if(n < 2) return 0;
        int ans = 0;
        vector<int>& prev = points[0];
        for(int i = 1; i < n; i++){
            vector<int>& curr = points[i];
            ans += max(abs(curr[1] - prev[1]), abs(curr[0] - prev[0]));
            prev = curr;
        }
        return ans;
    }
};

struct token {
    vector<vector<int>> points;
    int ans;
    int res;
};  

void handle(token& data){
    Solution s;
    data.res = s.minTimeToVisitAllPoints(data.points);
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
    tokens[0] = {{{1,1},{3,4},{-1,0}}, 7};
    tokens[1] = {{{3,2},{-2,2}}, 5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}