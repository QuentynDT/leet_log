#pragma once

#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// --- LEETCODE DATA STRUCTURES ---

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline TreeNode* buildTree(const vector<int>& data, int null_val = -1001) {
    if (data.empty() || data[0] == null_val) return nullptr;

    TreeNode* root = new TreeNode(data[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (i < data.size() && !q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < data.size()) {
            if (data[i] != null_val) {
                current->left = new TreeNode(data[i]);
                q.push(current->left);
            }
            i++;
        }
        if (i < data.size()) {
            if (data[i] != null_val) {
                current->right = new TreeNode(data[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

inline void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode* buildList(const vector<int>& data) {
    if (data.empty()) return nullptr;
    ListNode* head = new ListNode(data[0]);
    ListNode* current = head;
    for (size_t i = 1; i < data.size(); ++i) {
        current->next = new ListNode(data[i]);
        current = current->next;
    }
    return head;
}

inline void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// --- DISPLAY OVERLOADS ---

inline void pre(TreeNode* root) {
    if (!root) return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}

inline void display(TreeNode* root) {
    if (!root) {
        cout << "[null]\n";
        return;
    }
    pre(root);
    cout << '\n';
}

inline void display(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << (current->next ? " -> " : "");
        current = current->next;
    }
    cout << " -> [null]\n";
}

inline void display(const bool x) {
    cout << boolalpha << x << noboolalpha << ' ';
}

template <typename T>
void display(const T& x) {
    cout << x << ' ';
}

template <typename T>
void display(const vector<T>& v) {
    cout << "[ ";
    for (const auto& x : v) {
        display(x);
    }
    cout << "]";
}

template <typename T>
void display(const vector<vector<T>>& m) {
    cout << '\n';
    for (const auto& v : m) {
        display(v);
        cout << '\n';
    }
}

// --- TIMER & FORMATTING ---

inline int dig(long long x) {
    if (x <= 0) return 1;
    return static_cast<int>(floor(log10(x))) + 1;
}

inline void showRunTime(const high_resolution_clock::time_point& start,
                        const high_resolution_clock::time_point& end) {
    auto t = end - start;
    auto t_ms = duration_cast<milliseconds>(t).count();
    auto t_us = duration_cast<microseconds>(t).count();
    auto t_ns = duration_cast<nanoseconds>(t).count();

    int width = 15 + dig(t_ms) + dig(t_us) + dig(t_ns);
    string space(width, '-');

    cout << space << '\n';
    cout << t_ms << " ms | " << t_us << " us | " << t_ns << " ns\n";
    cout << space << '\n';
}

struct CleanDoubleFacet : num_put<char> {
protected:
    iter_type do_put(iter_type out, ios_base& str, char fill, double val) const override {
        char buf[64];
        int len = snprintf(buf, sizeof(buf), "%.4f", val);
        if (char* dot = strchr(buf, '.')) {
            char* end = buf + len - 1;
            while (*end == '0') --end;
            if (*end == '.') --end;
            len = static_cast<int>(end - buf + 1);
        }
        return copy_n(buf, len, out);
    }
};
