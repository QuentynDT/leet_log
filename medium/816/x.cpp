#include "../../timer.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.size() - 2);
        for (int i = 1; i < s.size(); i++){    
            for (const string& x : splits(s.substr(0, i))){
                for (const string& y : splits(s.substr(i))){
                    ans.emplace_back(format("({}, {})", x, y));
                }
            }
        }
        return ans;
    }

private:
    vector<string> splits(const string& s) {
        if (s.empty() || s.size() > 1 && s.front() == '0' && s.back() == '0') return {};
        if (s.back() == '0') return {s};
        if (s.front() == '0') return {"0." + s.substr(1)};

        vector<string> c{s};
        for (int i = 1; i < s.size(); i++){
            c.emplace_back(format("{}.{}", s.substr(0, i), s.substr(i)));
        }
        return c;
    }
};

struct token {
    string s;
    vector<string> ans;
    vector<string> res;
};

void handle(token& data){
    Solution s;
    data.res = s.ambiguousCoordinates(data.s);
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
    tokens[0] = {"(123)", {"(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"}};
    tokens[1] = {"(0123)", {"(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"}};
    tokens[2] = {"(00011)", {"(0, 0.011)","(0.001, 1)"}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}