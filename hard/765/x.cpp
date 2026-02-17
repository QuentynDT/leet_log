#include "../../timer.h"

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps = 0;
        const int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        for (int i = 0; i < n; i += 2) {
            const int first = row[i], second = row[i + 1];
            const int partner = first ^ 1;
            if (second != partner) {
                swaps++;
                int j = pos[partner];
                swap(row[i + 1], row[j]);
                pos[second] = j;
            }
        }
        return swaps;
    }
};

struct token {
    vector<int> row;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minSwapsCouples(data.row);
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
    tokens[0] = {{0,2,1,3}, 1};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}