#include "../../timer.h"

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int first = weight[0], ans = 0;
        const int n = weight.size();
        for(int i = 1; i < n; i++){
            if(weight[i] < first){
                first = -1;
                ans++;
            } else if(first == -1){
                first = weight[i];
            }
        }
        return ans;
    }
};

struct token {
    vector<int> weight;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxBalancedShipments(data.weight);
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
    tokens[0] = {{2, 5, 1, 4, 3}, 2};
    tokens[1] = {{483,199,268,147,415,510}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}