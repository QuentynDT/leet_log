#include "../../timer.h"

class Solution {
public:
    string f(string s){
        string a = s + '1';
        for(char& c : s){
            c = ((c - '0') ^ 1) + '0';
        }
        a.append(s | views::reverse | ranges::to<string>());
        return a;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        while(n--){ 
            s = f(s);
            if(s.size() > k) break;
            
        }
        return s[k - 1];
    }
};

struct token {
    int n;
    int k;
    char ans;
    char res;
};

void handle(token& data){
    Solution s;
    data.res = s.findKthBit(data.n, data.k);
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
    tokens[0] = {20, 16, '1'};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}