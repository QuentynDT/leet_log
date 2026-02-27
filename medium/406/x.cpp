#include "../../timer.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        ranges::sort(people, ranges::less{}, [](const vector<int>& person) {
        return pair<int, int>{-person[0], person[1]};
        });

        for (const vector<int>& person : people){
            ans.insert(ans.begin() + person[1], person);
        }
        
        return ans;
    }
};

struct token {
    vector<vector<int>> people;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.reconstructQueue(data.people);
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
    tokens[0] = {{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}, {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}