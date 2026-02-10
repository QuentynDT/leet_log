#include "../../timer.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
private:
    bool dfs(TreeNode* root, TreeNode* left, TreeNode* right){
        if(!root) return true;
        if(left && root->val <= left -> val || right && root->val >= right -> val) return false;
        return dfs(root -> left, left, root) && dfs(root -> right, root, right);
    }
};


struct token {
    TreeNode* root;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isValidBST(data.root);
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
    tokens[0] = {buildTree({2, 1, 3}), true};
    tokens[1] = {buildTree({5,1,4,-1,-1,3,6}), false};
    tokens[2] = {buildTree({5,1,6,-1,-1,2,8}), false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}