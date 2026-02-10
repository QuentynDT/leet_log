#include "../../timer.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == 0) ans.push_back(curr->val);

                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        return ans;
    }
};

struct token {
    TreeNode* root;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.rightSideView(data.root);
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
    const int n = 4;
    vector<token> tokens(n);
    tokens[0] = {};
    tokens[1] = {};
    tokens[2] = {};
    tokens[3] = {};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}