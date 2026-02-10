#include "../../timer.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head), *prev = dummy, *curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};

struct token {
    ListNode* head;
    int val;
    ListNode* ans;
    ListNode* res;
};

void handle(token& data){
    Solution s;
    data.res = s.removeElements(data.head, data.val);
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
    tokens[0] = {buildList({1,2,6,3,4,5,6}), 6, buildList({1,2,3,4,5})};
    tokens[1] = {buildList({}), 1, buildList({})};
    tokens[2] = {buildList({7, 7, 7, 7}), 7, buildList({})};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}