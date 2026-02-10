
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z){
        if(x == y) return (x + y + z) * 2;
        return (1 + z + 2 * min(x, y)) * 2;
    }
};
template <typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};
template <typename... Ts>
Overload(Ts...) -> Overload<Ts...>;
struct token {
    int x;
    int y;
    int z;
    int ans;
};
int main(){
    Solution s;
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {2, 5, 1, 12};
    tokens[1] = {3, 2, 2, 14};
    tokens[2] = {8, 8, 8, 48};
    vector<int> reslist(n);
    auto handle = [&](token& data) -> int {
        return s.longestString(data.x, data.y, data.z);
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
