#include "../../timer.h"

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        vector<pair<int, int>> points = {{x1, y1}, {x1, y2}, {x2, y2}, {x2, y1}, {xCenter, yCenter}};
        auto dist = [&](int i, int j) -> double {
            pair<int, int>& a = points[i];
            pair<int, int>& b = points[j];
            return sqrt(pow(b.second - a.second, 2) + pow(b.first - a.first, 2));
        };
        vector<double> dists(4);
        for(int i = 0; i < 4; i++){
            dists[i] = dist(i, (i + 1) % 4);
        }
        for(int i = 0; i < 4; i++){
            double r1r2 = dist(i, (i + 1) % 4);
            double cr1 = dist(i, 4);
            double cr2 = dist((i + 1) % 4, 4);
            cout << r1r2 << ' ' << cr1 << ' ' << cr2 << '\n';
            double sp = (r1r2 + cr1 + cr2 ) / 2;
            double area = sqrt(sp * (sp - r1r2) * (sp - cr1) * (sp - cr2));
            cout << area << '\n';
            //this is the triangle formed by point i, point i + 1, and xCenter
            //3 side lengths are dists[i],
        }
        return false;
    }
};

struct token {
    int radius;
    int xCenter;
    int yCenter;
    int x1;
    int y1;
    int x2;
    int y2;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.checkOverlap(data.radius, data.xCenter, data.yCenter, data.x1, data.y1, data.x2, data.y2);
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
struct CleanDoubleFacet : num_put<char> {
protected:
    iter_type do_put(iter_type out, ios_base& str, char fill, double val) const override {
        char buf[64];
        int len = snprintf(buf, sizeof(buf), "%.4f", val);
        if (char* dot = strchr(buf, '.')) {
            char* end = buf + len - 1;
            while (*end == '0') --end;
            if (*end == '.') --end;
            len = static_cast<int>(end - buf + 1);
        }
        return copy_n(buf, len, out);
    }
};
int main(){
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({1, 0, 0, 1, -1, 3, 1, true});
    tokens.push_back({2000, 10000, 10000, 10000, 10000, -10000, -10000, true});
    cout.imbue(locale(cout.getloc(), new CleanDoubleFacet));
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
