#include "../../timer.h"

class Solution {
public:
    bool match(bool up, int prev, int curr){
        return up && (prev < curr) || !up && (prev > curr);
    }
    int longestMountain(vector<int>& arr) {
        bool up = true;
        int mx = 0, count = 0;
        const int n = arr.size();
        for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n  ";
        for(int i = 1; i < n; i++){
            cout << "we are going " << (up ? "up" : "down") << " from " << arr[i - 1] << ' ' << arr[i] << ' ';
            bool matched = match(up, arr[i - 1], arr[i]);
            if (matched) cout << "matched!";
            cout << '\n';
            if(matched){
                if(count == 0) count = 2;
                else count++;
            } else {
                if(!up){
                    mx = max(mx, count);
                    count = 0;
                    up = !up;
                }
            }
            cout << count << ' ';
        }
        cout << '\n';
        return mx;
    }
};

struct token {
    vector<int> arr;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.longestMountain(data.arr);
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
    tokens.push_back({{2,1,4,7,3,2,5}, 5});
    tokens.push_back({{2,2,2}, 0});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
