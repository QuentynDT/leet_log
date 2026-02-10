#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n){
        vector<int> facts(10, 1);
        for(int i = 1; i < 10; i++){
            facts[i] = facts[i - 1] * i;
        }
        int ans = 1;
        for(int k = 0; k < n; k++){
            ans += 9 * (facts[9]/facts[9 - k]);
        }
        return ans;
    }
};
template <typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};
template <typename... Ts>
Overload(Ts...) -> Overload<Ts...>;
struct token {
    int n;
    int ans;
};
int main(){
    Solution s;
    const int n = 9;
    vector<token> tokens(n);
    tokens[0] = {0, 1};
    tokens[1] = {1, 10};
    tokens[2] = {2, 91};
    tokens[3] = {3, 739};
    tokens[4] = {4, 5275};
    tokens[5] = {5, 32491};
    tokens[6] = {6, 168571};
    tokens[7] = {7, 712891};
    tokens[8] = {8, 2345851};
    vector<int> reslist(n);
    auto handle = [&](token& data) -> int {
        return s.countNumbersWithUniqueDigits(data.n);
    };
    auto display = Overload {
        [](int& x) {
            cout << x << '\n';
        },
        [](const vector<int>& v) {
            for (const auto& x : v) {
                cout << x << ' ';
            }
            cout << '\n';
        },
        [](const vector<vector<int>>& m) {
            cout << '\n';
            for (const auto& v : m) {
                for (const auto& x : v) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
        },
        [](string& s) {
            cout << s << '\n';
        }
    };
    auto dig = [](long long x) -> int {
        if (!x) {
            return 1;
        }
        return floor(log10(x)) + 1;
    };
    auto runTests = [&]() -> void {
        cout << '\n';
        for(int i = 0; i < n; i++){
            reslist[i] = handle(tokens[i]);
            cout << "Output: ";
            display(reslist[i]);
            cout << "Expected answer: ";
            display(tokens[i].ans);
            cout << '\n';
        }
    };
    auto start = high_resolution_clock::now();
    runTests();
    auto end = high_resolution_clock::now();
    auto t = end - start;
    auto t_ms = duration_cast<milliseconds>(t).count();
    auto t_μs = duration_cast<microseconds>(t).count();
    auto t_ns = duration_cast<nanoseconds>(t).count();
    const int x = 15 + dig(t_ms) + dig(t_μs) + dig(t_ns);
    string space(x, '-');
    cout << space << '\n';
    cout << t_ms << " ms | " << t_μs << " μs | " << t_ns << " ns" << '\n';
    cout << space << '\n';
    return 0;
}