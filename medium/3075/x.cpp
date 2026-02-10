#include "../../timer.h"

// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         long long ans = 0;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i = happiness.size() - 1; i >= 0; i--){
//             pq.push(happiness[i]);
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }
//         vector<int> list;
//         while(!pq.empty()){
//             list.push_back(pq.top());
//             pq.pop();
//         }
//         ranges::sort(list, greater<>{});
//         for(int i = 0; i < k; i++){
//             const int& x = list[i];
//             if(x <= i) break;
//             ans += x - i;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         long long ans = 0;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i = happiness.size() - 1; i >= 0; i--){
//             pq.push(happiness[i]);
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }
//         while(!pq.empty()){
//             ans += max(pq.top() - --k, 0);
//             pq.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        nth_element(happiness.begin(), happiness.end() - k, happiness.end());
        sort(happiness.end() - k, happiness.end(), greater<int>());

        long long ans = 0;
        const int n = happiness.size();
        for (int i = 0; i < k; ++i) {
            const int val = happiness[n - k + i] - i;
            if (val <= 0) break;
            ans += val;
        }
        
        return ans;
    }
};

struct token {
    vector<int> happiness;
    int k;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.maximumHappinessSum(data.happiness, data.k);
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
    tokens[0] = {{1,2,3}, 2, 4};
    tokens[1] = {{1,1,1,1}, 2, 1};
    tokens[2] = {{2,3,4,5}, 1, 5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}