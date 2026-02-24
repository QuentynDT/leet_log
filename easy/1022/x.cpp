#include "../../timer.h"

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0, x = 0;
        auto dfs = [&](this auto self, TreeNode* root, int x){
            if (root == nullptr) return;
            x = x * 2 + root->val;
            if (root->left == nullptr && root->right == nullptr){
                ans += x;
            }
            self(root->left, x);
            self(root->right, x);
        };
        dfs(root, 0);
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
    data.res = s.sumRootToLeaf(data.root);
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
    vector<token> tokens(n);
    tokens[0] = {};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}