#include "../../timer.h"

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        const int n = s.length();
        int first = -1, second = -1;
        int c = 0, o = 0, m = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                c++;
            } else {
                o++;
                if(c){
                    first = second;
                    second = c;
                    c = 0;
                    cout << "first is " << first << " and second is " << second << '\n';
                    if(first != -1){
                        m = max(m, first + second);
                    }
                }
            }
        }
        if(c){
            first = second;
            second = c;
            if(first != -1){
                m = max(m, first + second);
            }
        }
        cout << m << ' ' << o << '\n';
        return m + o;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxActiveSectionsAfterTrade(data.s);
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
    tokens.push_back({"01", 1});
    tokens.push_back({"0100", 4});
    tokens.push_back({"00", 0});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
