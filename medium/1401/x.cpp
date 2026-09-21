#include "../../timer.h"

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        const int nX = clamp(xCenter, x1, x2), nY = clamp(yCenter, y1, y2);
        const int dx = xCenter - nX, dy = yCenter - nY;

        return (dx * dx + dy * dy) <= (radius * radius);
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
