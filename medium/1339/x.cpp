#include "../../timer.h"

class Solution {
public:
    int sumify(TreeNode* root){
        if(!root) return 0;
        root -> val += sumify(root -> left) + sumify(root -> right);
        return root->val;
    }
    int maxProduct(TreeNode* root) {
        constexpr int kMod = 1'000'000'007;
        int sum = sumify(root);
        long long mx = 0, curr;
        auto search = [&](this auto self, TreeNode* root) -> void {
            if(!root) return;
            curr = 1LL * (sum - root->val) * root->val;
            mx = max(mx, curr);
            self(root -> left);
            self(root -> right);
        };
        search(root);
        return mx % kMod;
    }
};

struct token {
    TreeNode* root;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxProduct(data.root);
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
    tokens[0] = {buildTree({1,2,3,4,5,6}), 110};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}