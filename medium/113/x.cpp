#include "../../timer.h"

class Solution {
public:
    void dfs(TreeNode* root, int& sum, vector<int>&& path, vector<vector<int>>& ans){
        if(root == nullptr) return;
        path.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && root -> left == nullptr && root-> right == nullptr){
            ans.push_back(path);
        }
        dfs(root -> left, sum, move(path), ans);
        dfs(root -> right, sum, move(path), ans);
        sum += root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        dfs(root, targetSum, {}, ans);
        return ans;
    }
};


struct token {
    TreeNode* root;
    int targetSum;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.pathSum(data.root, data.targetSum);
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
    tokens[0] = {buildTree({5,4,8,11,-1,13,4,7,2,-1,-1,5,1}), 22, {{5,4,11,2},{5,8,4,5}}};
    tokens[1] = {buildTree({1,2,3}), 5, {{}}};
    tokens[2] = {buildTree({1,2}), 0, {{}}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}