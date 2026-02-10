#include "../../timer.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res = "";
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;

        res += ".";
        unordered_map<long long, int> mp;
        
        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }
            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};

struct token {
    int numerator;
    int denominator;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.fractionToDecimal(data.numerator, data.denominator);
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
    tokens[0] = {1, 2, "0.5"};
    tokens[1] = {2, 1, "2"};
    tokens[2] = {4, 333, "0.(012)"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}