#include "../../timer.h"

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i < n; i++){
            if(!prime[i]) continue;
            for(int j = i * i; j < n; j+= i){
                prime[j] = false;
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.countPrimes(data.n);
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
    tokens[0] = {10, 4};
    tokens[1] = {0, 0};
    tokens[2] = {1, 0};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}