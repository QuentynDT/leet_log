#include "../../timer.h"

class Solution {
public:
    struct pair_hash {
        inline size_t operator()(const std::pair<int, int> & v) const {
            return v.first * 31 + v.second;
        }
    };
    int maxLength(vector<string>& arr) {
        const int n = arr.size();
        vector<int> bit(n, 0);
        for(int i = 0; i < n; i++){
            bool dup = false;
            for(char& c : arr[i]){
                int x = c - 'a';
                if((bit[i] >> x) & 1){
                    dup = true;
                    break;
                }
                bit[i] |= (1 << x);
            }
            if(dup) bit[i] = 0;
        }
        int mx = 0;
        unordered_map<pair<int, int>, int, pair_hash> memo;
        auto dfs = [&](this auto self, int i, int b) -> int {
            if(i == n){
                return 0;
            }
            auto it = memo.find({i, b});
            if (it != memo.end()) return it->second;
            int res = self(i + 1, b);
            if(bit[i] != 0 && (b & bit[i]) == 0) {
                res = max(res, (int)arr[i].size() + self(i + 1, b | bit[i]));
            }
            memo[{i, b}] = res;
            return memo[{i, b}];
        };
        return dfs(0, 0);
    }
};

struct token {
    vector<string> arr;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxLength(data.arr);
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
    tokens.push_back({{"un","iq","ue"}, 4});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}