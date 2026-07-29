#include "../../timer.h"
vector<int> v;
bool done = false;
class Solution {
public:
    void build(){
        done = true;
        for(int i = 8; i > 0; i--){
            for(int j = 0; j < i; j++){
                int x = 0;
                for(int k = 0; k < (10 - i); k++){
                    x = x * 10 + (j + k + 1);
                }
                v.push_back(x);
            }
        }
        for(int& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    vector<int> sequentialDigits(int low, int high) {
        if(!done){
            build();
        }
        auto start = lower_bound(v.begin(), v.end(), low);
        auto end = upper_bound(v.begin(), v.end(), high);
        return vector<int>(start, end);
    }
};

struct token {
    int low;
    int high;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.sequentialDigits(data.low, data.high);
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
    tokens.push_back({100, 300, {123,234}});
    tokens.push_back({1000, 13000, {1234,2345,3456,4567,5678,6789,12345}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
