#include "../../timer.h"

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        auto pre = [&](this auto self, TreeNode* root, int x) -> void {
            if(!root) return;
            if(x >= sums.size()){
                sums.push_back(root->val);
            } else {
                sums[x]+=root->val;
            }
            self(root -> left, x + 1);
            self(root -> right, x + 1);
        };
        pre(root, 0);
        int mx = INT_MIN, mi = 0;
        for(int i = 0; i < sums.size(); i++){
            if(sums[i] > mx){
                mi = i;
                mx = sums[i];
            }
        }
        return mi + 1;
    }
};

struct token {
    TreeNode* root;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxLevelSum(data.root);
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
    tokens[0] = {buildTree({1,7,0,7,-8,-1,-1}), 2};
    tokens[1] = {buildTree({989,-1,10250,98693,-89388,-1,-1,-1,-32127}), 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}