#include "../../timer.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string dir;
        while (getline(ss, dir, '/')) {
            if (!dir.empty()) {
                if(dir == ".") continue;

                if(dir == ".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(dir);
                }
            }
        }
        string ans = "";
        for(string& s : st){
            ans += '/';
            ans += s;
        }
        return ans == "" ? "/" : ans;
    }
};

struct token {
    string path;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.simplifyPath(data.path);
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
    const int n = 5;
    vector<token> tokens(n);
    tokens[0] = {"/home/", "/home"};
    tokens[1] = {"/home//foo/", "/home/foo"};
    tokens[2] = {"/home/user/Documents/../Pictures", "/home/user/Pictures"};
    tokens[3] = {"/../", "/"};
    tokens[4] = {"/.../a/../b/c/../d/./", "/.../b/d"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}