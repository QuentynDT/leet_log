#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        const int m = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long ans = 0;
        long d1 = labs(dividend);
        long d2 = labs(divisor);
        while (d1 >= d2) {
            long k = 1;
            while (k * 2 * d2 <= d1){
                k *= 2;
            }
            d1 -= k * d2;
            ans += k;
        }
        return m * ans;
    }
};
template <typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};
template <typename... Ts>
Overload(Ts...) -> Overload<Ts...>;
int main(){
    Solution s;
    const int n = 2;
    vector<int> dividendlist = {10, 7};
    vector<int> divisorlist = {3, -3};
    vector<int> anslist = {3, -2};
    vector<int> reslist(n);
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
            reslist[i] = s.divide(dividendlist[i], divisorlist[i]);
            cout << "Output: ";
            display(reslist[i]);
            cout << "Expected answer: ";
            display(anslist[i]);
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