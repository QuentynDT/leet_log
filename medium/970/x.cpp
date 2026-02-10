#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

class Solution {
public:
    vector<int> powerfulInteger(int x, int y, int bound){
        vector<bool> seen(bound + 1);
        int a = 1, b = 1;
        for(int i = 0; a <= bound; i++){
            b = 1;
            for(int j = 0; a + b <= bound; j++){
                seen[a + b] = true;
                if(y == 1) break;
                b *= y;
            }
            if(x == 1) break;
            a *= x;
        }
        vector<int> ans;
        for(int i = 1; i <= bound; i++){
            if(seen[i]) ans.push_back(i);
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
int main(){
    Solution s;
    const int n = 2;
    vector<int> xlist = {2, 3};
    vector<int> ylist = {3, 5};
    vector<int> boundlist = {10, 15};
    vector<vector<int>> anslist = {{2, 3, 4, 5, 7, 9, 10}, {2, 4, 6, 8, 10, 14}};
    vector<vector<int>> reslist(n);
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
            reslist[i] = s.powerfulInteger(xlist[i], ylist[i], boundlist[i]);
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