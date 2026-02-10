#include "../../timer.h"
class Solution {
public:
    string originalDigits(string s){
        vector<int> count(10);
        for(char& c : s){
            if(c == 'z') count[0]++;
            if(c == 'o') count[1]++;
            if(c == 'w') count[2]++;
            if(c == 'h') count[3]++;
            if(c == 'u') count[4]++;
            if(c == 'f') count[5]++;
            if(c == 'x') count[6]++;
            if(c == 's') count[7]++;
            if(c == 'g') count[8]++;
            if(c == 'i') count[9]++;
        }
        count[1] -= count[0] + count[2] + count[4];
        count[3] -= count[8];
        count[5] -= count[4];
        count[7] -= count[6];
        count[9] -= count[5] + count[6] + count[8];
        string res;
        for(int i = 0; i < 10; i++){
            if(count[i]) res += string(count[i], i + '0');
        }
        return res;
    }
};
struct token {
    string s;
    string ans;
    string res;
};
int main(){
    
    const int n = 4;
    vector<token> tokens(n);
    tokens[0] = {"owoztneoer", "012"};
    tokens[1] = {"fviefuro", "45"};
    tokens[2] = {"zeroonetwothreefourfivesixseveneightnine", "0123456789"};
    tokens[3] = {"ozerrezo", "00"};
    auto handle = [&](token& data) -> string {
        Solution s;
        return s.originalDigits(data.s);
    };
    auto runTests = [&]() -> void {
        cout << '\n';
        for(int i = 0; i < n; i++){
            tokens[i].res = handle(tokens[i]);
            cout << "Output: ";
            display(tokens[i].res);
            cout << "Expected answer: ";
            display(tokens[i].ans);
            cout << '\n';
        }
    };
    auto start = high_resolution_clock::now();
    runTests();
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}