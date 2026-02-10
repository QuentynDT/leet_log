#include "../../timer.h"

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int& x : nums){
            int d = 0, s = 0, i;
            for(i = 2; i * i < x; i++){
                if(x % i == 0){
                    if(d == 0) d = i;
                    else {
                        d = 0;
                        break;
                    }
                }
            }
            if(i * i == x) continue;
            if(d > 0 && d * d < x){
                ans += 1 + d + x/d + x;
            }
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.sumFourDivisors(data.nums);
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
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {{21,4,7}, 32};
    tokens[1] = {{21,21}, 64};
    tokens[2] = {{1,2,3,4,5}, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}