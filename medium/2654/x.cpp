#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

class Solution {
public:
    int minOperations(vector<int> nums){
        const int n = nums.size();
        int ans = 0;
        int tgcd = 0;
        for(int& x : nums){
            tgcd = gcd(tgcd, x);
            if(x > 1){
                ans++;
            }
        }
        if(ans < n) return ans;
        if(tgcd != 1) return -1;
        int mn = n;
        for(int i = 0; i < n; i++){
            int g = nums[i];
            for(int j = i + 1; j < n; j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    mn = min(mn, j - i);
                }
            }
        }
        return n + mn - 1;
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
    const int n = 4;
    vector<vector<int>> numslist = {{2, 6, 3, 4}, {2, 10, 6, 14}, {5, 6, 1, 4}, {6,10,15}};
    vector<int> anslist = {4, -1, 3, 4  };
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
            reslist[i] = s.minOperations(numslist[i]);
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