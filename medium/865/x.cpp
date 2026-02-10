#include "../../timer.h"

class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root -> left), depth(root -> right));
    }
    bool dfs(int d, int i, TreeNode* ans, TreeNode* root){
        if(!root) return false;
        if(i == d) return true;
        bool x = dfs(d, i + 1, ans, root -> left);
        bool y = dfs(d, i + 1, ans, root -> right);
        if(x || y) ans = root;
        return x || y;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = depth(root);
        TreeNode* ans = root;
        cout << d << '\n';
        dfs(d, 1, ans, root);
        return root;
    }
};

struct token {
    TreeNode* root;
    TreeNode* ans;
    TreeNode* res;
};

void handle(token& data){
    Solution s;
    data.res = s.subtreeWithAllDeepest(data.root);
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
    tokens[0] = {buildTree({3,5,1,6,2,0,8,-1,-1,7,4}), buildTree({2, 7, 4})};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}