#include "../../timer.h"

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        int x = min(need1, need2); 
        if(costBoth < cost1 && costBoth < cost2){
            ans = 1LL * costBoth * max(need1, need2);
        } else if (costBoth > cost1 && costBoth > cost2) {
            if(costBoth > cost1 + cost2){
                ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
            } else {
                ans = 1LL * x * costBoth + 1LL * (need2 - x) * cost2 + 1LL * (need1 - x) * cost1;
            }
        } else if(costBoth >= cost1 && costBoth <= cost2){
            ans = 1LL * need2 * costBoth + 1LL * max(need1 - need2, 0) * cost1;
        } else if(costBoth <= cost1 && costBoth >= cost2){
            ans = 1LL * need1 * costBoth + 1LL * max(need2 - need1, 0) * cost2;
        }
        return ans;
    }
};

struct token {
    int cost1;
    int cost2;
    int costBoth;
    int need1;
    int need2;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.minimumCost(data.cost1, data.cost2, data.costBoth, data.need1, data.need2);
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
    const int n = 5;
    vector<token> tokens(n);
    tokens[0] = {3, 2, 1, 3, 2, 3};
    tokens[1] = {5, 4, 15, 2, 3, 22};
    tokens[2] = {8, 4, 5, 3, 2, 15};
    tokens[3] = {50, 55, 72, 5, 3, 316};
    tokens[4] = {6, 38, 6, 10, 8, 60};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}