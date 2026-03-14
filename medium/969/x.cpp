#include "../../timer.h"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        const int n = arr.size();
        auto reverse = [&](int k) -> void {
            for(int i = 0; i < k / 2; i++){
                swap(arr[i], arr[k - i - 1]);
            }
        };
        vector<int> ans;
        for(int i = n; i > 0; i--){
            if(i != arr[0]){
                int j;
                for(j = 0; j < n; j++){
                    if(arr[j] == i){
                        break;
                    }
                }
                ans.push_back(j + 1);
                reverse(j + 1);
                
            }
            if(i > 1){
                ans.push_back(i);
                reverse(i);
            }
        }
        return ans;
    }
};

struct token {
    vector<int> arr;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.pancakeSort(data.arr);
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
    tokens.push_back({{3,2,4,1}, {4, 2, 4, 3}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}