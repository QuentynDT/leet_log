#include "../../timer.h"

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char c) {
        constexpr pair<int, int> dirs[] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        char d = (c == 'W') ? 'B' : 'W';
        auto match = [&](int currR, int currC, char x){
            return currR < 8 && currC < 8 && currR >= 0 && currC >= 0 && board[currR][currC] == x;
        };
        for(int i = 0; i < 8; i++){
            cout << "Current dirs = " << dirs[i].first << ", " << dirs[i].second << '\n';
            int currR = rMove, currC = cMove;
            int length = 0;
            do {
                currR += dirs[i].first;
                currC += dirs[i].second;
                length++;
                cout << "     " << currR << ' ' << currC << ' ' << length << " and opposite is " << d << '\n';
                if(!match(currR, currC, d)) {
                    cout << "The current cell (" << currR << ", " << currC << ") is " << c << '\n';
                    break;
                }
            } while(true);
            if(match(currR, currC, c) && length > 1){
                return true;
            }
        }
        return false;
    }
};

struct token {
    vector<vector<char>> board;
    int rMove;
    int cMove;
    char color;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.checkMove(data.board, data.rMove, data.cMove, data.color);
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
    tokens.push_back({{{'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'.','.','.','W','.','.','.','.'},{'W','B','B','.','W','W','W','B'},{'.','.','.','B','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','W','.','.','.','.'}}, 4, 3, 'B'});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
