#include "../../timer.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            stack<int> st;
            for (int j = 0; j <= n; j++) {
                while (!st.empty() && (j == n || heights[st.top()] > heights[j])) {
                    const int h = heights[st.top()];
                    st.pop();
                    const int w = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, h * w);
                }
                st.push(j);
            }
        }
        return ans;
    }
};
 
struct token {
    vector<vector<char>> matrix;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maximalRectangle(data.matrix);
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
    tokens[0] = {{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}, 6};
    tokens[1] = {{{'0'}}, 0};
    tokens[2] = {{{'1', '0'}}, 1};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}