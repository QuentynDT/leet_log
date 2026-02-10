#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int> data) {
    if (data.empty() || data[0] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(data[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < data.size() && !q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < data.size()) {
            int left_val = data[i];
            if (left_val != -1) {
                current->left = new TreeNode(left_val);
                q.push(current->left);
            }
            i++; 
        }
        if (i < data.size()) {
            int right_val = data[i];
            if (right_val != -1) {
                current->right = new TreeNode(right_val);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(const vector<int>& data) {
    if (data.empty()) return nullptr;
    ListNode* head = new ListNode(data[0]);
    ListNode* current = head;
    for (size_t i = 1; i < data.size(); ++i) {
        current->next = new ListNode(data[i]);
        current = current->next;
    }
    return head;
}
void pre(TreeNode* root){
    if(!root) return;
    cout << root -> val << ' ';
    pre(root -> left);
    pre(root -> right);

}
void display(TreeNode* root){
    pre(root);
    cout << '\n';
}
void display(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << (current->next ? " -> " : "");
        current = current->next;
    }
    cout << " [null]\n";
}
void display(const bool x){
    cout << boolalpha << x << noboolalpha << ' ';
}

template <typename T>
void display(const T& x) {
    cout << x << ' ';
}

template <typename T>
void display(const vector<T>& v) {
    for (const auto& x : v) {
        display(x);
    }
    cout << '\n';
}

template <typename T>
void display(const vector<vector<T>>& m) {
    cout << '\n';
    for (const auto& v : m) {
        display(v);
    }
}

int dig(long long x){
    if (!x) {
        return 1;
    }
    return floor(log10(x)) + 1;
}
void showRunTime(high_resolution_clock::time_point& start, high_resolution_clock::time_point& end){
    auto t = end - start;
    auto t_ms = duration_cast<milliseconds>(t).count();
    auto t_μs = duration_cast<microseconds>(t).count();
    auto t_ns = duration_cast<nanoseconds>(t).count();
    const int x = 15 + dig(t_ms) + dig(t_μs) + dig(t_ns);
    string space(x, '-');
    cout << space << '\n';
    cout << t_ms << " ms | " << t_μs << " μs | " << t_ns << " ns" << '\n';
    cout << space << '\n';
}