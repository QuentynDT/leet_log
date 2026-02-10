#include "../../timer.h"

class Solution {
public:
    void dfs(TreeNode* root, int path, int& ans) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            ans += path * 10 + root->val;
            return;
        }
        dfs(root->left, path * 10 + root->val, ans);
        dfs(root->right, path * 10 + root->val, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};

struct token {
    TreeNode* root;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.sumNumbers(data.root);
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
    tokens[0] = {buildTree({1, 2, 3}), 25};
    tokens[1] = {buildTree({4, 9, 0, 5, 1}), 1026};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}