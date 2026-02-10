#include "../../timer.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool f1 = false, f2 = false;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                f1 = true;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                f2 = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(f1){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(f2){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};

struct token {
    vector<vector<int>> matrix;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    s.setZeroes(data.matrix);
    data.res = data.matrix;
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
    const int n = 2;
    vector<token> tokens(n);
    tokens[0] = {{{1,1,1},{1,0,1},{1,1,1}}, {{1,0,1},{0,0,0},{1,0,1}}};
    tokens[1] = {{{0,1,2,0},{3,4,5,2},{1,3,1,5}}, {{0,0,0,0},{0,4,5,0},{0,3,1,0}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}